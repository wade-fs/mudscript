#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("大比目魚",({"hilabut"}));
set("long","哇。。。兩隻眼睛生長在同一邊耶。。。好奇怪的魚有\n");
set("race","人類");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",20);
set("int",30);
set("per",30);
set("str", 25);
set("con", 30);
set("force",250);
set("max_force",450);
set("max_kee",450);
set("kee",450);
set("combat_exp", 4000);
setup();
}
