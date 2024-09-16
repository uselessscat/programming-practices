//! This is a crate
//! <div class="warning">A big warning!</div>

/// This is a constant
pub const CONSTANT: u32 = 100;

/// foo is a function
/// 
pub fn foo(x: u32, y: u32) -> u32 {
    x + y
}

// This contains markdown
/// # Bar
///
/// | hello | world |
/// |-------|-------|
/// | foo   | bar   |
pub fn foo2() {}

/// This is a module
pub mod bar {
    /// This is a function
    fn baz() {}

    /// This is a struct
    pub struct AStruct {
        /// This is a field
        pub field: u32,
    }

    /// A function with code examples
    ///
    /// # Examples
    ///
    /// ```
    /// let x = 1;
    /// let y = 2;
    /// let z = projects::add(x, y);
    /// assert_eq!(z, 3);
    /// ```
    pub fn add(x: u32, y: u32) -> u32 {
        x + y
    }
}
