// 獨孤老人 by anmy 99/05/05 for 回收魔龍eq
#include <ansi.h>
#include "../start.h"
 
inherit NPC;

void create()
{
	set_name("獨孤老人", ({"lonely old man","man" }) );
	set("gender", "男性");
        set("nickname", HIM + "龍之賸" + NOR);
	set("age", 71);

set("long","你看到一位老人在你眼前,似乎他正在尋找收集有魔龍裝備的有緣人\n");
        set("per", 40);
	set("str", 25);
	set("con", 20);
	set("combat_exp", 10000000);
        set("no_kill",1);
	setup();
}

int accept_fight(object me)
{
	return
notify_fail("獨孤老人咳了咳緩緩的說：這位"+RANK_D->query_respect(me)+"別開我玩笑了好嗎？\n老身年邁體虛,怎有資格指點您呢..\n");
}

int accept_object(object who , object item)
{
	if( item->query("id")=="mdragon-eq" ) {

tell_object(who,"原本老人的眼神軟弱無力，一瞬間眼神一亮\n他豪爽的往你一拍：小子！真有你的了！！\n\n");
                if( !who->query("quests/歸還魔龍裝備") )
                    {		
//     who->add("standby", 4);

tell_object(who,HIY + "獨孤老人狂傲的笑了一陣子.\n" + NOR);
tell_object(who,HIR + "哈～哈～哈～哈～哈～哈～哈～哈～\n" + NOR);
tell_object(who,HIY + "一陣力氣油然而生, 你似乎多了好幾倍的保護了\n\n" + NOR);
tell_object(who,HIW + "原來獨孤老人以秘法使你身上的替身狂增四個\n" + NOR);

			who->set("quests/歸還魔龍裝備", 1);
		}
}
}
