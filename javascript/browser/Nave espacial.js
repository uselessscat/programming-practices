<html>

<head>
    <script>
        var controller;

        window.onload = e => {
            controller = new Controller();
        }

        class Controller {
            static MOVE_RIGHT = 1;
            static MOVE_LEFT = -1;

            static FUEL_PICK = 1;
            static FUEL_DROP = -1;

            constructor() {
                let element = document.getElementById('my-canvas');

                this.canvas = {
                    element,
                    context: element.getContext('2d')
                }

                this.data = {
                    ship: {
                        tankSize: 15,
                        fuel: 0,
                        position: 0
                    },
                    stations: {
                        alienDistance: 23,
                        originFuel: 45
                    }
                }

                this.data.droppedFuel = Array(this.data.stations.alienDistance + 1).fill(0);
                this.data.droppedFuel[0] = this.data.stations.originFuel;

                this.__addKeysListener();

                this.draw();
            }

            __addKeysListener() {
                document.onkeyup = e => {
                    switch (e.code) {
                        case 'ArrowRight':
                            this.move(Controller.MOVE_RIGHT); break;
                        case 'ArrowLeft':
                            this.move(Controller.MOVE_LEFT); break;
                        case 'ArrowUp':
                            this.fuel(Controller.FUEL_PICK); break;
                        case 'ArrowDown':
                            this.fuel(Controller.FUEL_DROP); break;
                    }
                }
            }

            move(to) {
                if (this.data.ship.fuel > 0) {
                    if (this.data.ship.position + to >= 0
                        && this.data.ship.position + to <= this.data.stations.alienDistance) {
                        this.data.ship.position += to;
                        this.data.ship.fuel--;
                    }
                }
                
                this.draw();
            }

            fuel(action) {
                switch (action) {
                    case Controller.FUEL_PICK:
                        if (this.data.droppedFuel[this.data.ship.position] > 0
                            && this.data.ship.fuel < this.data.ship.tankSize) {
                            this.data.droppedFuel[this.data.ship.position]--;
                            this.data.ship.fuel++;
                        }
                        break;
                    case Controller.FUEL_DROP:
                        if (this.data.ship.fuel > 0) {
                            this.data.droppedFuel[this.data.ship.position]++;
                            this.data.ship.fuel--;
                        }
                        break;
                }

                this.draw();
            }

            draw() {
                // limpiar el canvas
                this.canvas.context.clearRect(
                    0,
                    0,
                    this.canvas.element.width,
                    this.canvas.element.height
                );

                // dibuja la regla y los marcadores
                const ctx = this.canvas.context,
                    width = this.canvas.element.width,
                    height = this.canvas.element.height,

                    shipPos = this.data.ship.position,
                    startHPos = width * 0.1,
                    endHPos = width * 0.9,
                    middleHeigth = height / 2,
                    spacing = (endHPos - startHPos) / this.data.stations.alienDistance;

                ctx.textAlign = "center";

                drawLine(ctx, startHPos, middleHeigth - 30, endHPos, middleHeigth - 30);

                for (let i = 0; i <= this.data.stations.alienDistance; i++) {
                    let position = startHPos + i * spacing;

                    drawLine(ctx, position, middleHeigth - 32, position, middleHeigth - 25);
                    ctx.fillText(i, position, middleHeigth - 35);
                }

                // dibujar la nave
                ctx.beginPath();
                ctx.arc(startHPos + spacing * shipPos, middleHeigth, 10, 0, 2 * Math.PI);
                ctx.closePath();
                ctx.stroke();

                // combustible de la nave 
                ctx.fillText(this.data.ship.fuel, startHPos + spacing * shipPos, middleHeigth + 3);

                // dibujar combustible dejado
                for (let i = 0; i <= this.data.droppedFuel.length; i++) {
                    let position = startHPos + i * spacing;

                    if (this.data.droppedFuel[i] > 0) {
                        ctx.fillText(this.data.droppedFuel[i], position, middleHeigth + 25);
                    }
                }
            }

        }

        function drawLine(ctx, from_x, from_y, to_x, to_y) {
            ctx.beginPath();
            ctx.moveTo(from_x, from_y);
            ctx.lineTo(to_x, to_y);
            ctx.closePath();

            ctx.stroke();
        }
    </script>
</head>

<body>
    <h1>nave</h1>
    <a href="https://www.youtube.com/watch?v=Fj2hTS5Kjyw">Ver video</a>
    <p>controls:</p>
    <ul>
        <li><button onclick="controller.move(Controller.MOVE_RIGHT);">Right</button> Moverse der.</li>
        <li><button onclick="controller.move(Controller.MOVE_LEFT);">Left</button> Moverse iz.</li>
        <li><button onclick="controller.fuel(Controller.FUEL_PICK);">Up</button> Tomar combustible</li>
        <li><button onclick="controller.fuel(Controller.FUEL_DROP);">Down</button> Dejar combustible</li>
    </ul>
    <canvas id="my-canvas" style="border: 1px black solid;" width="500" height="500"></canvas>
</body>

</html>
