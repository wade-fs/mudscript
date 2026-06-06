#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("棘鬣魚",({"porgy"}));
set("long","海中生物無奇不有，居然連這種全身長刺的魚也有\n");
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
set("force",150);
set("max_force",400);
set("max_kee",400);
set("kee",300);
set("combat_exp", 3000);
setup();
}
