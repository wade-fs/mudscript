// d/city/gate/gate_inn.c
// 金石府城・關外車馬店 (北關驛道歇腳)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北關門前・關外車馬店");
    set_long("這是一間開在北關校場東側的粗木客棧。\n"
             "往來極北荒原與鎮風要塞的鏢客商旅多在此洗去風塵。跑堂小二老皮正麻利地\n"
             "端著大碗燒酒與醬牛肉在桌間穿梭，角落裡時常能打探到荒原獸潮與極北冰暴的最新風向。\n"
             "向西邁出客棧門檻，便是北關前校場。\n");

    set_exits(([
        "west": "/d/city/gate/gate_plaza.c",
    ]));

    set("is_outdoor", 0);
}
