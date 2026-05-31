//crclan.c 創建一個幫派的指令 by Chan(10.28.98)
//限定由Admin以上的大神來使用
//1999 5/11 修正 by chan

#include <clan.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object  ob;
        string  id, cname, cid;

        if( !str )
                return notify_fail("指令格式﹕crclan <玩家id> <幫派名稱> <幫派的英文名稱>\n");
        if( sscanf(str,"%s %s %s", id, cname, cid) != 3 )
                return notify_fail("指令格式﹕crclan <玩家id> <幫派名稱> <幫派的英文名稱>\n");
        if( !ob = find_player(lower_case(id)) )
                return notify_fail("沒有這個人。\n");
                if( wiz_level(me)<5)
                 return notify_fail("admin以上的巫師才能用這個指令。\n");
        if( !CLAN_D->create_clan(id, cid, cname) )
                return notify_fail("這個幫派已經存在了。\n");
        if(CLANV_D->create_clanv(cid))
        ob->set( "clan/name", cname );
        ob->set( "clan/id", cid );
        ob->set( "clan/rank", 1 );
        ob->set( "clan/home", CLAN_HOME + cid + "/room/hall.c" );
        ob->set( "clan/passwd", "0" );
        ob->set( "clan/title", "幫派老大" );
        CHANNEL_D->do_channel( me, "mud",
                "快報!!快報!!"+ob->query("name")+"在狂想大陸上成立了"+cname+"這個幫派。\n");

        return 1;
}

int help(object me)
{
        write(@HELP

指令格式:crclan <玩家id> < 幫派名稱> <幫派的英文名稱>

使用此指令能讓玩家建立幫派的指令。
例如:crclan chan 天神門 god

HELP
    );
        return 1;
}

