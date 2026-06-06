#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("巴拉金梭魚",({"barracuda"}));
set("long","這是什麼魚呀？看來海中生物種類還是真多耶........n");
set("race","人類");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",20);
set("int",30);
set("per",30);
set("str", 35);
set("con", 30);
set("force",500);
set("max_force",500);
set("max_kee",1500);
set("kee",1500);
set("combat_exp", 5000);
setup();
}
