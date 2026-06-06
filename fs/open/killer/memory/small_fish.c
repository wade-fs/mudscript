#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set("title","小魚");
set_name("時鯉",({"chi-li","chi","li"}));
set("long","為莫塔湖的鎮湖之魚，相傳是葉孤成所飼養的魚。\n");
set("race","人類");
set("gender","雌性");
set("attitude","aggressive");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",40);
set("int",30);
set("per",30);
set("str", 30);
set("con", 30);
set("force",300);
set("max_force",300);
set("max_kee",800);
set("kee",800);
set("combat_exp", 80000);
set_skill("move",80);
set_skill("dodge",80);
set_skill("parry",60);
setup();
}
