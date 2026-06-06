// 增加少林廚藝學院的quest相關 2010/09/06 by blazakira

#include <ansi.h>
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
        set_name("小二",({"small two","small","two"}));
        set("gender", "男性" );
        set("age",25);
        set("long", "天龍客棧的小二 , 他正忙著招呼客人 .\n");
        set("attitude", "friendly");
        set("combat_exp",30000);
        set("nickname",HIY + "利牙快嘴" + NOR);
        set("vendor_goods", ({
        "/obj/example/chicken_leg",
        "/obj/example/dumpling",
        "/obj/example/wineskin",
		"/open/bonze/food_quest/meat", //設定為直接販賣
        }) );

        setup();
}
void greeting(object ob)
{
        command("say 最近生意真差，沒啥客人住房。 ");
        command("say 還好還有一位老人住宿，否則本店要關門囉。");
}

int accept_kill(object ob)
{
 command("say 沒有看到我在忙嗎?真不知好歹，敢動到我頭上!");
 command("say 納命來!!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 小兄弟，我現在忙著招呼客人，等一下才陪你玩。");
return 0;
}
