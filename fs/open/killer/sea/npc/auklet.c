#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("小海雀",({"auklet"}));
set("long","活動於海洋天空上，以吃魚為生，但是人類不知道看起來像不像魚類\n");
set("race","人類");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "頭部", "身體" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",40);
set("int",30);
set("per",30);
set("str", 40);
set("con", 30);
set("force",620);
set("max_force",620);
set("max_kee",1100);
set("kee",1100);
set("combat_exp", 12000);
set_skill("dodge",40);
setup();
}
