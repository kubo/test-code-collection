fn main() {
    let mut n: u64 = 0x3ff0000000000000;
    let mut nerr = 0;

    for _ in 0..100 {
        let float_value: f64 = unsafe { std::mem::transmute(n) };
        if float_value.to_string().parse::<f64>().unwrap() != float_value {
            println!("round trip error: {:016x}, {}", n, float_value);
            nerr += 1
        }
        n += 1;
    }
    println!("error count: {}", nerr);
}
