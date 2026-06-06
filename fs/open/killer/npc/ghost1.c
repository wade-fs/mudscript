#include <ansi.h>
inherit NPC;
void create()
{
    set_name("屍魂人",({"ghost"}) );
    set("long",
   "黑牙聯的禁法，所產生的怪物，將屍體浸在藥水中，只聽施藥者的命令\n");
    set("race", "人類");
    set("gender","男性");
    set("combat_exp",550000);
    set("age",40);
    set("title","黑牙聯成員");
    set("kee",400);
    set("max_kee",400);
    set("bellicosity",300);
    set_skill("dagger",70);
    setup();
    carry_object("/open/killer/obj/dagger")->wield();
}
