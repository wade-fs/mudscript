// c_create.c

#include <clan.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help( object me )
{
        write(@HELP

指令格式: c_create <幫主ID> <幫派中文名稱> <幫派英文名稱>
指令說明: 於狂想空間創立新的幫派。

HELP
    );
        return 1;
}

int main( object me, string str )
{
	object  ob;
	string  id, cname, cid;

	if( !me->query("clan") || wiz_level(me)<5 )
		return 0;
	if( !str || sscanf( str, "%s %s %s", id, cname, cid ) != 3 )
		return help(me);
        if( !ob = find_player(lower_case(id)) )
                return notify_fail("沒有這個人。\n");
        if( !CLAN_D->create_clan( id, cid, cname ) )
		return notify_fail("這個幫派已經存在了。\n");
        if(CLANV_D->create_clanv(cid))
        ob->set( "clan/name", cname );
        ob->set( "clan/id", cid );
        ob->set( "clan/rank", 1 );
        ob->set( "clan/passwd", "0" );
        ob->set( "clan/title", "幫派老大" );
	CHANNEL_D->do_channel( me, "mud",
		"\n快報!!快報!!"+ob->query("name")+"在狂想大陸上成立了"+cname+"這個幫派。\n");

        return 1;
}

