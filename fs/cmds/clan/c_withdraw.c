// by ACKY 04/18/00

int help( object me )
{
	write("
	c_withdraw <數量> <貨幣種類>：於幫派錢莊提款。

		   貨幣種類：
		 	    diamond ： 鑽石
		 	    cash    ： 銀票
			    gold    ： 黃金

	幫派存款少於一百萬兩黃金時, 不提供此服務。
");
	return 1;
}

int main( object me, string arg )
{
	int amount, value;
	object n_money;
	string kind, clan_id;

	if( !me->query("clan" ) ) return 0;

	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此處並非貴幫之地盤。\n");

	clan_id = me->query("clan/id");

	if( file_name(environment(me)) != CLAN_D->clan_query( clan_id, "bank" ) )
		return notify_fail( "此處並非錢莊。\n" );

	if( !arg )
		return "/cmds/clan/c_deposit.c"->balance( me );

	if( sscanf( arg, "%d %s", amount, kind ) != 2 )
		return help(me);

        if( file_size("/obj/money/"+kind+".c") < 0 )
                return notify_fail("錢莊內沒有這種貨幣。\n");

        if( amount < 1 )
                return notify_fail("提款一次至少要一個。\n");

	value = call_other( "/obj/money/"+kind, "query", "base_value" );

	if( value < 10000 )
                return notify_fail("錢莊內沒有這種貨幣。\n");

        value /= 10000;
        value *= amount;

        if( me->query("clan/bank") < value || value < 1 )
		return notify_fail("您在錢莊裡沒有存這麼多錢。\n");

	if( value > 1000000 )
		return notify_fail( "金額不得一次提領超過黃金一百萬兩。\n" );

        if( CLAN_D->clan_query( clan_id, "gold" ) < 1000000 )
		return notify_fail("目前貴幫週轉不靈，無法提款。\n");

        me->add( "clan/bank", -value );
	CLAN_D->add_money( clan_id, -value );
	CLAN_D->clan_set( clan_id, "member_gold", CLAN_D->clan_query( clan_id, "member_gold" )-value );

        n_money = present(kind + "_money", me);

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(me);
                n_money->set_amount(amount);
        }
        else
                n_money->add_amount(amount);

        write( sprintf("您一共提出%s%s%s。\n",
		chinese_number(amount),
		n_money->query("base_unit"),
		n_money->query("name") ) );

        return 1;
}

