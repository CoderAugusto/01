add x2, x0, x1
sll x1, x2, x2
or x2, x2, x1
andi x2, x1, 16
addi x3, x2, -243
mv x10, x11
sw x0, 8(x10)
sh x2, 4(x12)
sb x4, 6(x16)