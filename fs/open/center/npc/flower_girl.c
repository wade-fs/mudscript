#include <obj.h>
#include <ansi.h>
#include "/open/open.h"
 
inherit F_VENDOR;
static int reboot_time = 0;

string give_flower();

void create()
{
        set_name("賣花的小女孩", ({ "selling flower girl", "girl" }) );
        set("nickname",HIW"可憐沒人愛"NOR);
        set("gender", "女性" );
        set("age", 16);
        set("long", @LONG
這是一位有著碧髮藍睛的賣鮮花的漂漂女孩，由於她受母親之託, 所
以在此賣鮮花, 希望帶給狂想的玩者一點小小心意。你也可以問她有
關贈品的事(ask girl about 贈品)

LONG);
        set("attitude", "friendly");
        set("rank_info/respect", "小妹妹");
        set("combat_exp",150000);

        set("vendor_goods", ({
            CENTER_OBJ"flower",
        }) );
        set("no_kill",1);

        set("inquiry",([
          "贈品":"嗯, 我這裡有賣剩的一點鮮花, 你要的話我可以給你",
          "鮮花":(: give_flower :),
        ]));

        set("chat_msg", 5);
        set("chat_msg", ({
            "小女孩說道: 有人想要買鮮花送女友嗎。\n",
        }) );

        set("greeting_msg", ({
            "小女孩說道: 快來買鮮花喔。\n",
        }) );
        setup();
}

string give_flower()
{
        object who, item;
        who = this_player();

        if( who->query("quests/happy") || who->query_temp("flower")==1 )
                return "你不是已經領了一束鮮花了嗎？\n";
        else if( who->query_temp("鮮花")==2 ) {
                item = new("/open/center/obj/flower");
                item->move(who);
                message_vision("耶誕小女孩給$N一束鮮花。\n", who);
                who->set_temp("flower", 1);
                return"真是的,還好我還有備份！給你吧!\n";
        }
        else {
                item = new("/open/center/obj/flower");
                item->move(who);
                printf("小女孩給%s一個%s。\n",
                who->query("name"),item->short() );
                who->set_temp("flower", 1);
                return "祝你新年快樂囉 :P。\n";
        }
}
