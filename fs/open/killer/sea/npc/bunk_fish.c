#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("龍頭魚",({"Bombay duck","duck"}));
set("long","少見的魚類，看來是已經來到奇怪的地方，不然怎麼連這種魚都看的到\n");
set("race","人類");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",50);
set("int",30);
set("per",30);
set("str", 50);
set("con", 30);
set("force",1800);
set("max_force",1800);
set("max_kee",2000);
set("kee",2000);
set("combat_exp", 35000);
set_skill("dodge",60);
setup();
}
