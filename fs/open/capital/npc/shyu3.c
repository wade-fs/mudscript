// guard.c

#include <ansi.h>
#include "/open/open.h"

inherit NPC;
void create()
{
                  set_name("徐肉軒", ({ "lo shyu","lo","shyu" }) );
	set("gender", "男性" );
 set("age",20);
        set("str",35);
        set("cor",35);
	set("cps", 25);
	set("int", 15);
     set("long","他是徐大夫的龜兒子,專門幫人變臉的,\n"
                 "你可以問他有關變臉的事情。\n");
	set("combat_exp",338);
	set("attitude", "peaceful");
        set("inquiry", ([
            "變臉"    :"如果你準備好了,就下 faceoff 指令,好讓我開始手術。",
            "變性"    :"變性ㄚ!!那是我老爸的專長,我可不會,別想叫我退費哦。",
            "退費"    :"他ㄌㄟㄌㄟ的,敢叫我退費",
        ]) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        carry_object("/obj/cloth")->wear();
}

