// d/city/gate/gate_south_inn.c
// 金石府城・南關車馬小棧 (黑石鋪流民與挑夫落腳點)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南關門下・車馬小棧");
    set_long("這是一間倚靠南城牆根搭建的低矮泥磚客棧。\n"
             "屋內幾張油膩斑駁的粗木條桌旁坐滿了灰頭土臉的挑夫與南方逃難流民。\n"
             "空氣中飄散著粗劣大麥茶與老旱煙的氣味。掌櫃老劉正靠在櫃檯後算賬，\n"
             "幾個流民牙子在角落裡低聲私語，暗中替城內各工坊招攬短工。\n"
             "向東走出柴門，便是重兵把守的南關城門。\n");

    set_exits(([
        "east": "/d/city/gate/gate_south.c",
    ]));

    set("is_outdoor", 0);
}
