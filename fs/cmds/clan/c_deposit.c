// by ACKY 04/18/00

#include <ansi.h>

inherit F_CLEAN_UP;

int balance( object me )
{
	write( sprintf( HIG + "《" + HIC + "%|10s" + HIG + "》" + HIY + "幫派錢莊 " + NOR + "-\n\n" + HIW + "\t擁有%s錠黃金。\n" + NOR,
		me->query("clan/name"), chinese_number(me->query("clan/bank")) ) );
	return 1;
}

int help( object me )
{
	write( "
	c_deposit <數量> <貨幣種類>

		於幫派錢莊存款。

		貨幣種類:
			diamond : 鑽石
			cash    : 銀票
			gold    : 黃金

	c_deposit
		於幫派錢莊查詢存款餘額。

	注意, 若脫離幫派, 存於錢莊內的錢將歸原幫派所有。
");
	return 1;
}

int main( object me, string arg )
{
	int amount, value, member_gold;
	object n_money, ob;
	string kind, clan_id;

	if( !me->query("clan" ) ) return 0;

	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此處並非貴幫之地盤。\n");

	clan_id = me->query("clan/id");

	if( file_name(environment(me)) != CLAN_D->clan_query( clan_id, "bank" ) )
		return notify_fail( "此處並非錢莊。\n" );

	if( !arg )
		return balance( me );

	if( sscanf( arg, "%d %s", amount, kind ) != 2 )
		return notify_fail("\ncdeposit <數量> <貨幣種類>\n");

	n_money = present(kind + "_money", me);

        if( !n_money || file_size("/obj/money/"+kind+".c") < 0 )
                return notify_fail("您身上沒有這種貨幣。\n");

        if( amount < 1 )
                return notify_fail("存多一點嘛。\n");

	if( n_money->query("base_value") < 10000 )
                return notify_fail("存值錢一點的東西吧!\n");

        if( n_money->query_amount() < amount)
                return notify_fail("您身上並沒有那麼多" + n_money->query("name") +"。\n");

        value = n_money->query("base_value")/10000;
        value *= amount;

	member_gold = CLAN_D->clan_query( clan_id, "member_gold" );

	if( (CLAN_D->clan_query( clan_id, "gold" )+value) > 2000000000 ||
	    (member_gold                          +value) > 2000000000 )
		return notify_fail("幫派錢莊的財產已多到放不下囉!\n");

        ob = new("/obj/money/" + kind);
	n_money->add_amount(-amount);
        me->add( "clan/bank", value);
	CLAN_D->add_clanset( clan_id, "member_gold", value );
	CLAN_D->add_money( clan_id, value );
        write( "您一共存入"+chinese_number(amount)+ob->query("base_unit")+ob->query("name")+"。\n" );

        return 1;
}
