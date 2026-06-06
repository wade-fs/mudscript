// guard.c

#include <ansi.h>
#include "/open/open.h"

inherit NPC;
void create()
{
                  set_name("徐大夫", ({ "doctor shyu","doctor","shyu" }) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",35);
	set("cps", 25);
	set("int", 15);
     set("long","剛從宮內退休的徐大夫,專門幫人剪爛佛,\n"
                 "你可以問他有關整容的事情。\n");
	set("combat_exp",338);
	set("attitude", "peaceful");
        set("inquiry", ([
            "變性"    :"如果你準備好了,就下 change 指令,好讓我開始手術。",
            "整容"    :"整容喔!!那是我兒子的專長,我可不會,別想叫我退費哦。",
            "退費"    :"退你媽的頭啦！",
        ]) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        carry_object("/obj/cloth")->wear();
}

