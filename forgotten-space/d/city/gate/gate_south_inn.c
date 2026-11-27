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

    set_touch("default", YEL "低矮土牆邊粗木長凳有些搖晃，碗裡糙米粥的熱氣暖著冰涼指尖。" NOR);
    set_smell("default", YEL "粗茶水氣、濕衣烘烤味與剛從外縣逃難進關的行旅風塵氣。" NOR);
    set_listen("default", WHT "老劉與跑腿小廝在櫃後悄悄互通有無的低語，夾著門外南關盤查喧鬧。" NOR);

    add_action_rule("publish_case", ([
        "targets": ({ "public_posting", "sealed_petition" }),
        "quest_verb": "publish_case",
        "quest_target_from_arg": 1,
        "usage_msg": "請決定四線物證合璧後的出牌策略：publish_case public_posting（通衢張榜）或 publish_case sealed_petition（密呈府衙）。",
        "sensory_msgs": ([
            "public_posting": HIR "老劉與五子連夜刷印四線鐵證摘要貼上南關照壁，消息如野火般捲過六縣與金石長街！" NOR,
            "sealed_petition": CYN "你將四線原件與密呈帖仔細封蠟，交由老劉暗樁直遞府衙後門，靜候三方會審一網打盡！" NOR
        ]),
        "exp_gain": 15
    ]));

    spawn_npc("/clone/npc/gate_south_inn_laoliu.c");
    spawn_npc("/clone/npc/gate_south_runner.c");
    spawn_npc("/clone/npc/su_ningshuang.c");
}
