// c_room_make.c by ACKY

inherit F_CLEAN_UP;

string get_file_name(string dir);
void create_room(string file);

int help( object me )
{
	write(
"\n\tc_room_make: 擴張幫派地盤。
\n\t幫內人數(c_join)愈多, 幫派威望(c_prestige)愈高, 能佔領的地盤愈大。\n\n"
	);
	return 1;
}

int main( object me )
{
	string	code, dir, file, clan;
	object	room;

	if( !me->query("clan") )
                return 0;
        if( me->query("clan/rank") > 3 )
                return notify_fail( "無權使用此指令。\n" );
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此區域並非本幫所屬地盤。\n" );
	clan = me->query("clan/id");
	if( CLAN_D->clan_query( clan, "gold" ) < 1000 )
		return notify_fail( "幫派存款不足。\n" );
	if( sizeof(get_dir("/open/clan/" + clan + "/room/")) >
		CLAN_D->clan_query( clan , "develop" )/100 + sizeof(CLAN_D->clan_query( clan, "members" )) )
		return notify_fail( "幫派區域擴張已達上限。\n" );

	dir = CLAN_D->get_clan_dir(me);
	file = dir + get_file_name(dir);

	code = @CODE
inherit ROOM;
void create() {
	set( "short", "新區域" );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
CODE;

	write_file( file, code, 1 );
	if( !room = load_object(file) )
		return notify_fail( "建造新區域失敗。\n" );
	else
		write( "花了壹千兩黃金建造新區域。\n" );
	if( wizardp(me) )
		write( "新建的檔案名稱為: " + file + "\n" );
	CLAN_D->add_money( me->query("clan/id"), -1000 );
	return 1;
}

string get_file_name( string dir )
{
        int i;
	i = 1;
        while(i++)
		if( file_size( dir+"room/room"+i+".c" ) == -1 )
			return "room/room"+i+".c";
}

