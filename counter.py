import os
import plotly.express as px
import pandas as pd


def load_allowed_extensions(file_path):
    try:
        with open(file_path, "r", encoding="utf-8") as file:
            return set(line.strip() for line in file if line.strip())
    except Exception as e:
        print(f"Error reading allowed extensions file: {e}")
        return set()


class CodeLineCounter:
    def __init__(self, base_dir, extensions_file="allowed_extensions.txt"):
        self.base_dir = base_dir
        self.allowed_extensions = load_allowed_extensions(extensions_file)
        self.pending_extensions = set()
        self.nodes = {}

        self._initialize_root_node()

    def _initialize_root_node(self):
        self.nodes[self.base_dir] = {
            "id": self.base_dir,
            "label": os.path.basename(self.base_dir) or self.base_dir,
            "parent": "",
            "lines": 0
        }

    def count_code_lines(self, file_path):
        try:
            with open(file_path, "r", encoding="utf-8", errors="ignore") as file:
                return sum(1 for _ in file)
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
            return 0

    def process_directory(self):
        for dirpath, dirnames, filenames in os.walk(self.base_dir):
            self._ensure_directory_node(dirpath)

            for file in filenames:
                self._process_file(dirpath, file)

            self._ensure_subdirectory_nodes(dirpath, dirnames)

        self._propagate_line_counts()

    def _ensure_directory_node(self, dirpath):
        if dirpath not in self.nodes:
            parent = os.path.dirname(dirpath)
            self.nodes[dirpath] = {
                "id": dirpath,
                "label": os.path.basename(dirpath) or dirpath,
                "parent": parent,
                "lines": 0
            }

    def _process_file(self, dirpath, file):
        ext = os.path.splitext(file)[1].lower()

        if ext not in self.allowed_extensions:
            self.pending_extensions.add(ext)
            return

        full_path = os.path.join(dirpath, file)
        line_count = self.count_code_lines(full_path)

        self.nodes[full_path] = {
            "id": full_path,
            "label": file,
            "parent": dirpath,
            "lines": line_count
        }

        self.nodes[dirpath]["lines"] += line_count

    def _ensure_subdirectory_nodes(self, dirpath, dirnames):
        for d in dirnames:
            full_path = os.path.join(dirpath, d)
            if full_path not in self.nodes:
                self.nodes[full_path] = {
                    "id": full_path,
                    "label": d,
                    "parent": dirpath,
                    "lines": 0
                }

    def _propagate_line_counts(self):
        sorted_dirs = sorted(
            (n for n in self.nodes if os.path.isdir(n)),
            key=lambda p: p.count(os.sep),
            reverse=True
        )

        for d in sorted_dirs:
            if d == self.base_dir:
                continue
            parent = os.path.dirname(d)
            if parent in self.nodes:
                self.nodes[parent]["lines"] += self.nodes[d]["lines"]

    def generate_treemap(self):
        df = pd.DataFrame(self.nodes.values())
        fig = px.treemap(
            df,
            names="label",
            parents="parent",
            values="lines",
            ids="id",
            title="Code Lines Treemap",
            branchvalues="total",
        )
        fig.update_layout(margin=dict(t=50, l=25, r=25, b=25))
        fig.write_image("treemap.svg", width=1024)
        fig.show()


if __name__ == "__main__":
    base_directory = "."
    counter = CodeLineCounter(base_directory)
    counter.process_directory()
    print("Pending extensions:", list(counter.pending_extensions))
    counter.generate_treemap()
