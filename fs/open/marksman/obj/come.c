
inherit ITEM;
#include <ansi.h>

void create()
{
set_name(HIY + "哨子" + NOR,({ "come" }));
     set("long",
     "這是一個特製的哨子﹐可呼喚你的鳳凰﹐呼喚時請用(come-sum)\n"
     "﹐要請鳳凰回去時請(go-way)。\n");
     set("no_sell",1);     set("no_auc",1);     set("unit","個");
     set("save_obj",1);    set("call-in-Lbird","YES");
     setup();
}
void init()
{
     add_action("do_summon", "come-sum");
     add_action("do_home", "go-way");
}
int do_summon(string str, object me)
{
    object Lbird, env;

    seteuid(getuid());     me = this_player();     env = environment(me);
    if( me->query_temp("come-sum") )
    return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC + "唉呀" + CYN
    "～﹗" + HIC + "你真貪心" + CYN + "﹐" + HIC + "不都已經召出了一隻鳳凰了嗎" + CYN + "﹖\n" + NOR);
    if( !sizeof(me->query_mlists()) )
    return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC + "哇咧" + CYN
    "～" + HIC + "你連一隻寵物都沒有" + CYN + "﹐" + HIC + "更何況召喚鳳凰" + CYN + "﹗\n" + NOR);
    if( !str ) return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕"
    HIC + "你要呼喚誰來" + CYN + "﹖" + HIC + "請(mlist)查詢你的鳳凰" + CYN + "﹗\n" + NOR);
    if( !me->query_mlist(str) )
    return notify_fail(GRN + "<" + HIG + "鳳凰" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC
    "你並沒有養這種鳳凰吧" + CYN + "﹖\n" + NOR);
    if( file_size("/open/marksman/obj/"+str+".c") < 0
    &&  !find_object("open/marksman/obj/"+str) )
    return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC + "嗯" + CYN
    " ....." + HIC + "雖然你的確有養這隻寵物" + CYN + "﹐" + HIC + "不過這種鳳凰好像絕種了"
    CYN + "﹗\n" + HIC + "你還是另請高明吧" + CYN + "﹗\n" + NOR);
    Lbird = new("/open/marksman/obj/"+str);
    tell_room(env, HIY+me->name()+HIY + "用哨子吹了一聲口哨" + YEL + "﹐" + HIY
    "只見天空突然裂出一個洞" + YEL + "﹐" + HIY + "有一個不明物體衝了過來" + YEL + "﹗﹗\n\n" + NOR);
    if( me->is_fighting() ) me->start_busy(4); else me->start_busy(1);
    me->set_temp("come-sum","YES");
    Lbird->move(env);
    Lbird->set("level",me->query_mlist(str));
    Lbird->set("owner",me->query("id"));
    Lbird->set_leader(me);
    Lbird->set_skill("move",me->query_mlist(str));
    tell_room(env, HIY + "轉眼間風雲變色" + YEL + "﹐" + HIY + "一隻可愛的"
    +Lbird->name()+HIY + "出現在你面前" + YEL + "。\n\n" + NOR);
    write(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC + "成功\召出鳳凰" + CYN + "﹗\n" + HIW + "Ok.\n" + NOR);
    return 1;
}
int do_home(string str, object me)
{
    object Lbird, env;

    seteuid(getuid());
    me = this_player();
    env = environment(me);
    if( !str ) return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕"
    HIC + "你要叫誰回家呢" + CYN + "﹖\n" + NOR);
    if( !me->query_temp("come-sum") )
    return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC
    "你都還沒有召出鳳凰呢" + CYN + "﹗" + HIC + "要如何命令它回家" + CYN + "﹖\n" + NOR);
    if( me->query_temp("is_rid") == "Lbird"
    &&  me->query_temp("rider/myself") )
    return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC
    "你還騎著你的鳳凰喔" + CYN + "。\n" + NOR);
    if( !objectp(Lbird = present(str, env)) )
    return notify_fail(GRN + "<" + HIG + "寵物妖精" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC
    "你的鳳凰不見了說" + CYN + "﹗﹗\n" + NOR);
    if( Lbird->query("owner") != me->query("id") )
    return notify_fail(GRN + "<" + HIG + "恰吉" + GRN + ">" + HIC + " 說道" + CYN + "﹕" + HIC
    "這不是你的鳳凰吧" + CYN + "﹗" + HIC + "爽白爛呀" + CYN + "﹗\n" + NOR);
    me->delete_temp("come-sum");
    tell_room(env, HIG+me->name()+HIG + "輕聲的跟"+Lbird->name()+HIG + "說了一些話"
    GRN + "﹐" + HIG + "只見鳳凰展開翅膀，往天空飛去，轉眼間不見了。" + GRN + "﹗\n" + NOR);
    destruct(Lbird);
    return 1;

}
