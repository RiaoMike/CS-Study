function add(num1, num2) {
    num1 = num1.toString();
    num2 = num2.toString();

    var a = 0,
        b = 0;
    if (num1.indexOf('.') != -1) {
        a = num1.split('.')[1].length;
    }
    if (num2.indexOf('.') != -1) {
        b = num2.split('.')[1].length;
    }

    num1 = parseInt(num1.replace(".", ""));
    num2 = parseInt(num2.replace(".", ""));

    var diff;
    var max = b;
    if (a > b) {
        diff = a - b;
        max = a;
        for (var i = 0; i < diff; i++) {
            num2 = num2 * 10;
        }
    } else {
        diff = b - a;
        for (var i = 0; i < diff; i++) {
            num1 = num1 * 10;
        }
    }

    var sum = num1 + num2;
    var beishu = 1;
    for (var i = 0; i < max; i++) {
        beishu = beishu * 10;
    }
    sum = sum / beishu;

    return sum;

}

console.log(add(0.01, 0.123));