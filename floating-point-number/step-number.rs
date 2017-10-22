fn main() {
    let mut n: u64 = 0x3ff0000000000000;

    println!("  double in binary => text representation");
    for _ in 0..1000 {
        let float_value: f64 = unsafe { std::mem::transmute(n) };
        println!("  {:016x} => {}", n, float_value);
        n += 1;
    }
}
