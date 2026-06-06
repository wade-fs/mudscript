#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(YEL"二十五銅人"NOR,({"twenty-five master","master"}));
        set("long", @LONG
這裡共有二十五尊銅人立足，每一尊的表情，姿態皆不
相同，更奇怪的是每尊銅人的背後，都寫了一行詩句，
難道這便是魔教鞭法的奧義嗎？若想學習奧義，請使用
(learn)指令。

LONG);

        set("gender","男性");
        set("guild_master",1);
        set("class","poisoner");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",26);
        set("str", 44);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
        set("force",800);
        set_skill("forever-love",100);
       setup();
}


