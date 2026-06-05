/************************************************************
*  clan_war_officer.c by ACKY 06.22.00                      *
************************************************************/

/*
	MUD 時間	現實時間
	  6 分鐘	  1 秒鐘
*/

#include <ansi.h>

inherit NPC;
void	multipk_start();
void	multipk_timeout();
void	multipk_win( object ob );
void	multipk_lose( object ob );
void	multipk_round( object win, object lose );
void	multipk_over();
int	war_score( int exp );
string	where( object ob );

#define	AREA_PK	"/open/clan/area/pk/"

int	multipk_now    = 0,	// 戰爭是否開始
	multipk_time   = 0,	// 戰爭經過時間
	multipk_point1 = 0,	// 宣戰幫派戰績
	multipk_point2 = 0,	// 接戰幫派戰績
	multipk_money1 = 0,	// 宣戰幫派所得金錢
	multipk_money2 = 0;	// 接戰幫派所得金錢
mapping multipk = ([
	"十三吉祥"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"幽暗密林"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"逍遙聖境"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"陰曹地府"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"九天蒼龍"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"煙雨江南"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"傲雲山莊"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
	"天道無極"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"幽暗密林"	: ([ "war" : 0 ]),
		"逍遙聖境"	: ([ "war" : 0 ]),
		"陰曹地府"	: ([ "war" : 0 ]),
		"九天蒼龍"	: ([ "war" : 0 ]),
		"煙雨江南"	: ([ "war" : 0 ]),
		"傲雲山莊"	: ([ "war" : 0 ]),
		"天道無極"	: ([ "war" : 0 ])
			]),
		]);

mapping pk_map = ([
	0	: "thunder",
	1	: "wind",
	2	: "ice",
	3	: "fire",
	4	: "land",
	]);

mapping pk_nmap = ([
	"thunder"	: 0,
	"wind"		: 1,
	"ice"		  : 2,
	"fire"		: 3,
	"land"		: 4,
	]);

mapping pk_cmap = ([
	"thunder"	: "迅雷峰",
	"wind"		: "疾風崖",
	"ice"		  : "玄冰島",
	"fire"		: "烈燄谷",
	"land"		: "震天原",
	]);

string	multipk_clan1, multipk_clan2;		// 幫派ID 
object	*multipk_player1, *multipk_player2;	// 參戰名單 1.宣戰者 2.接戰者

void create()
{
//	string *clan_id = CLANV_D->fs_clan();
	set( "title", "幫派戰爭區域主持人");
	set_name( "鄭總管", ({ "clan_war officer", "officer" }) );
	set( "long", "\n他是幫派戰爭區域的主持人。\n" );      
	set( "clan/name", " 朝  廷 " );
	set( "race", "人類" );
	set( "gender", "男性" );
	set( "attitude", "friendly" );
	set( "no_kill", 1 );
	setup();
//	clan_id = fs_clan();
	multipk["煙雨江南"]["十三吉祥"]["player1"]= "acky";
}

void init()
{
	if( !query_heart_beat( this_object() ) )
		set_heart_beat(1);
	::init();
}

int do_exchange( object me )
{
	if( me->query("clan/exchange") >= (me->query("clan/war")/1000) ) {
		tell_object(me, HIY"鄭總管說道: 您目前戰績為 "+me->query("clan/war")+" 點, 還不到獎勵的標準。\n"NOR);
		return 1;
	}
	me->add( "clan/exchange", 1 );
	me->add( "standby", 1 );
	tell_object(me, HIY"鄭總管說道: 恭喜您獲得替身一個, 在緊要關頭他會替您遊地府, 代您走一趟的。\n"NOR);
	return 1;
}

int do_list( object me )
{
	string	*clan;
	int	i, j, clan_sum, count;
	
	clan = keys(multipk);
	clan_sum  = sizeof(clan);

	for( i=0; i<clan_sum; i++ )
		for( j=0; j<clan_sum; j++ )
			if( multipk[clan[j]][clan[i]]["war"] == 1 ) {
				printf( "%|10s 向 %|10s 宣戰。\n", clan[i], clan[j] );
				count++;
			}
	if( count==0 )		
		printf( HIC"無任何幫派發起戰爭, 狂想空間瀰漫著祥和之氣。\n"NOR );
	else
		printf( HIR"你察覺到%s股濃烈的殺氣...\n"NOR, CHINESE_D->chinese_number(count) );

	return 1;
}

int do_multipk( string clan2, string *player )
{
	int	n;
	object	me, ob;
	string	clan1, clan1_id;
 multipk_player1=({});multipk_player2=({}); 
	
	// clan1 發動戰爭的幫派 (主動者)
	// clan2 發動戰爭的對象 (被動者)

	me       = find_player( player[0] );
	clan1    = me->query( "clan/name" );
	clan1_id = me->query( "clan/id"   );
	
        if( CLAN_D->clan_query( clan1_id, "gold" ) < 1000000 )
		return notify_fail( "幫派存款不足一百萬兩黃金。\n" );
	
	if( multipk_now ) {
		tell_object( me, "目前幫派戰爭區域正有幫派對戰中, 請稍待。\n");
		return 1;
	}

	// multipk[被動幫派][主動幫派]
	//	["war"]		1: 願意參戰 0: 不願意參戰
	//	["player(1~5)"] 主動幫派參戰名單
         
	if( multipk[clan1][clan2]["war"] ) {

		// 接戰資料處理 clan1 接戰幫派 clan2 宣戰幫派
		CHANNEL_D->do_channel( me, "war", "我 -「"+me->query("clan/title")+"」接受"+clan2+"的戰書。\n"NOR);

		if( !ob = find_player(multipk[clan1][clan2]["player1"]) ) {
			CHANNEL_D->do_channel( this_object(), "war", clan2 + "懼怕與" + clan1 + "對戰, 逃走了。\n"NOR );
			multipk[clan1][clan2]["war"] = 0;
			return 1;
		}	
	}
	else { // 宣戰資料處理 clan1 宣戰幫派 clan2 接戰幫派
		CHANNEL_D->do_channel( me, "war", "我 -「"+me->query("clan/title")+"」向"+clan2+"宣戰。\n"NOR);
		multipk[clan2][clan1]["war"] = 1;
		for( n=1; n<6; n++ )
			multipk[clan2][clan1]["player"+n] = player[n];
		return 1;
	}

	// 開戰資料處理 multipk1 宣戰幫派 multipk2 接戰幫派
	multipk_clan1 = ob->query("id");
	multipk_clan2 = me->query("id");

     for( n=1; n<6; n++ ){
		if( find_player(multipk[clan1][clan2]["player"+n]) )
multipk_player1 += ({ find_player(multipk[clan1][clan2][sprintf("player%d",n)]) }) ;
}
	for( n=1; n<6; n++ )
		if( find_player(player[n]) )
multipk_player2 += ({ find_player(player[n]) });

	CHANNEL_D->do_channel( this_object(), "war", "【"+clan2+"】與【"+clan1+"】雙方將於六小時後開戰。\n"NOR); // MUD 6hr = REAL 1min

	multipk_now    = 1;
	multipk_time   = 1;

	return 1;
}

// 撤回宣戰
int do_end( object me, string type, string clan2 )
{
	// clan1 宣佈投降幫派 clan2 勝利幫派
	string	clan1;
	
	clan1 = me->query("clan/name");

	if( type == "multipk" ) {
		if( multipk[clan2][clan1]["war"] != 1 )
			tell_object( me, "貴幫並沒有對此幫派宣戰。\n");
		else {			
			tell_object( users(),
				HIW"\n【"+clan1+"】「"+me->query("clan/title")+"」"+me->query("name")+
				"("+me->query("id")+")送給【"+clan2+"】一封和平協議書。\n\n"NOR );
			multipk[clan2][clan1]["war"] = 0;
			return 1;
		}
	}
	return 1;
}

void heart_beat()
{
	// *multipk_player1, *multipk_player2; 參戰名單 1.宣戰者 2.接戰者

	if( multipk_now ) {
		if( multipk_time == 50 )
			CHANNEL_D->do_channel( this_object(), "war", "【" +
				CLAN_D->clan_query( multipk_clan1, "name" ) + "】與【" +
				CLAN_D->clan_query( multipk_clan2, "name" ) + "】之戰, 即將開始, 請雙方趕緊做好最後的準備。" );
		if( multipk_time == 60 )
			multipk_start();
		if( multipk_time > 300 ) // MUD 24hr = REAL 4min
			multipk_timeout();
	}
	
	multipk_time++;	
}

void multipk_judge( object ob )
{
	int n;
	string area;

	area = where(ob);

	if( ob->query("war/clan") == 1 )
		if( where(multipk_player2[pk_nmap[area]]) == area ) {
			tell_object( ob, "鄭總管說道: 尚未分出勝負。\n" );
			return;
		}
		else
			multipk_win( ob );

	else if( ob->query("war/clan") == 2 )
		if( where(multipk_player1[pk_nmap[area]]) == area ) {
			tell_object( ob, "鄭總管說道: 尚未分出勝負。\n" );
			return;
		}
		else
			multipk_win( ob );
}

void multipk_win( object ob )
{
	int	score;
	object	vs;
	
	tell_object( ob, HIC"鄭總管說道: 恭喜, 您獲勝了。\n"NOR );
	score = ob->query( "clan/war" ) + ob->query_temp( "war/score" );
	ob->set( "clan/war", score );
	tell_object( ob, "您的戰績升為 " + score + " 點。\n" );

	if( ob->query("war/clan")==1 ) {
		multipk_point1++;
		multipk_money1 += ob->query_temp("war/score")/10;
	}
	else if( ob->query("war/clan")==2 ) {
		multipk_point2++;
		multipk_money2 += ob->query_temp("war/score")/10;
	}
	
	if( vs = find_player(ob->query_temp("war/vs")) )
		multipk_round( ob, vs );
	else
		multipk_round( ob, ob );
        ob->remove_all_killer();
	ob->move( ob->query( "war/from" ) );
	ob->delete_temp( "war" );
}

void multipk_lose( object ob )
{
	int	score;
	object	vs; 

	tell_object( ob, HIC"鄭總管說道: 勝負已定, 您輸了。\n"NOR );
	score = ob->query( "clan/war" ) - war_score(ob->query("combat_exp"));
	ob->set( "clan/war", score );
	tell_object( ob, "您的戰績降為 " + score + " 點。\n" );

	vs = find_player(ob->query_temp("war/vs"));
	ob->remove_all_killer();
	ob->move( ob->query( "war/from" ) );
	ob->delete_temp( "war" );
	multipk_win( vs );
}

void multipk_round( object win, object lose )
{
	if( win->query_temp("war/clan")==1 )
		multipk_point1++;
	else
		multipk_point2++;
		
	if( win == lose )
		CHANNEL_D->do_channel( this_object(), "war", "【" + pk_cmap[win->query_temp("war/area")] + "】勝負已分, 勝者"HIW + win->query("name") + HIR"!" );
	else
		CHANNEL_D->do_channel( this_object(), "war", "【" + pk_cmap[win->query_temp("war/area")] + "】勝負已分,"HIW +
			lose->query("name") + HIR"慘遭屠戮, 勝者"HIW + win->query("name") + HIR"!" );
	
	if( (multipk_point1+multipk_point2)==5 )
		multipk_over();
}

void multipk_start()
{
	int n;
	object ob;

	multipk_point1 = 0;
	multipk_point2 = 0;

	CHANNEL_D->do_channel( this_object(), "war", "時辰已到,【" +
		CLAN_D->clan_query( multipk_clan1, "name" ) + "】與【" +
		CLAN_D->clan_query( multipk_clan2, "name" ) + "】之戰開始。" );

	for( n=0; n<5; n++ ) {
		if( multipk_player1[n] ) {
			ob->set_temp( "war/type", "multipk" );
			ob->set_temp( "war/clan", 1 );
			ob->set_temp( "war/area", pk_map[n] );
			ob->set_temp( "war/from", file_name(environment(ob)) );
			ob->set_temp( "war/vs", multipk_player2[n]->query("id") );
			if( multipk_player2[n] ) {
				ob->set_temp( "war/score", war_score(multipk_player2[n]->query("combat_exp")) );
				ob->set_temp( "war/vs", multipk_player2[n]->query("id") );
			}
			else {
				ob->set_temp( "war/score", 0 );
				ob->set_temp( "war/vs", "NONE" );
			}
			ob->move(AREA_PK+pk_map[n]+"_"+(random(9)+1));
		}
	}

	for( n=0; n<5; n++ ) {
		if( multipk_player2[n] ) {
			ob->set_temp( "war/type", "multipk" );
			ob->set_temp( "war/clan", 2 );
			ob->set_temp( "war/area", pk_map[n] );
			ob->set_temp( "war/from", file_name(environment(ob)) );
			if( multipk_player1[n] ) {
				ob->set_temp( "war/score", war_score(multipk_player1[n]->query("combat_exp")) );
				ob->set_temp( "war/vs", multipk_player1[n]->query("id") );
			}
			else {
				ob->set_temp( "war/score", 0 );
				ob->set_temp( "war/vs", "NONE" );
			}
			ob->move(AREA_PK+pk_map[n]+"_"+(random(9)+1));
		}
	}

}

void multipk_over()
{
	string clan_win, clan_lose;
	int point;

	if( multipk_point1 > multipk_point2 ) {
		clan_win  = multipk_clan1;
		clan_lose = multipk_clan2;
		point     = multipk_money1; 
	}
	else {
		clan_win  = multipk_clan2;						
		clan_lose = multipk_clan1;
		point     = multipk_money2;
	}

	CHANNEL_D->do_channel( this_object(), "war", "轟動武林, 驚動萬教的【" +
		CLAN_D->clan_query( multipk_clan1, "name" ) + " VS " +
		CLAN_D->clan_query( multipk_clan2, "name" ) + "】之戰終於結束。" );
	CHANNEL_D->do_channel( this_object(), "war", HIW +
		CLAN_D->clan_query( clan_win, "name" ) + HIR"戰勝"HIW +
		CLAN_D->clan_query( clan_lose, "name" ) + HIR"。" );
	CHANNEL_D->do_channel( this_object(), "war", HIW +
		CLAN_D->clan_query( clan_lose, "name" ) + HIR"需賠"HIW +
		CLAN_D->clan_query( clan_win, "name" ) + HIY"黃金" +CHINESE_D->chinese_number(point)+ "萬兩"HIR"。" );

	point *= 10000;
	CLAN_D->add_money  ( clan_win ,  point );
	CLAN_D->add_money  ( clan_lose, -point );
	CLAN_D->add_clanset( clan_lose, "develop", -point/10000 );

	log_file("clan/"+clan_win+"/WAR-"+ctime(time())[4..6], sprintf("%s 戰勝%|12s獲得黃金 %5d 萬兩\n",
		ctime(time())[0..15], CLAN_D->clan_query(clan_lose,"name"), point ));
	log_file("clan/"+clan_lose+"/WAR-"+ctime(time())[4..6], sprintf("%s 敗給%|12s賠款黃金 %5d 萬兩\n",
		ctime(time())[0..15], CLAN_D->clan_query(clan_win,"name"), point ));

	multipk_now    = 0;
	multipk_time   = 0;
	multipk_point1 = 0;
	multipk_point2 = 0;
	multipk_money1 = 0;
	multipk_money2 = 0;
}

void multipk_timeout()
{
	int	n;
	object	ob;
		
	CHANNEL_D->do_channel( this_object(), "war", "【" +
		CLAN_D->clan_query( multipk_clan1, "name" ) + " VS " +
		CLAN_D->clan_query( multipk_clan2, "name" ) + "】雙方已激戰整整一日。" );
	for( n=0; n<5; n++ ) {
		if( multipk_player1[n] )
			if( pk_cmap[where(ob)] ) {
				ob->remove_all_killer();
				ob->move( ob->query( "war/from" ) );
				ob->delete_temp( "war" );
			}
	}
	for( n=0; n<5; n++ ) {
		if( multipk_player2[n] )
			if( pk_cmap[where(ob)] ) {
				ob->remove_all_killer();
				ob->move( ob->query( "war/from" ) );
				ob->delete_temp( "war" );
			}
	}
	multipk_over();
}

string where( object ob )
{
	int	i;
	string	area;

	i = 24;
	area = file_name(environment(ob));

	if( area[16..22] == "multipk" )
		while( i++ )
			if( area[i] == '_' )
				return area[24..i-1];
	return "NONE";
}

int war_score( int exp )
{
	int level, i;

	i = exp-3000000;
	for( level=0; i>0; level++ )
		i-= (level)*1500;

	return level;
}

