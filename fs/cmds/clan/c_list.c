// by ACKY 02/14/2000
#include <ansi.h>

inherit F_CLEAN_UP;

int sort_member( string ob1 , string ob2 )
{
	return sizeof(CLAN_D->clan_query(ob2,"members")) -
		sizeof(CLAN_D->clan_query(ob1,"members"));
}

int sort_prestige( string ob1 , string ob2 )
{
	return CLAN_D->clan_query(ob2, "score") -
	       CLAN_D->clan_query(ob1, "score");
}

int sort_area( string ob1 , string ob2 )
{
	return sizeof(get_dir("/open/clan/"+ob2+"/room/room*.c")) -
		sizeof(get_dir("/open/clan/"+ob1+"/room/room*.c"));
}

int sort_money( string ob1 , string ob2 )
{
	return ( CLAN_D->clan_query( ob2, "gold" ) - CLAN_D->clan_query( ob2, "member_gold" ) ) -
		( CLAN_D->clan_query( ob1, "gold" ) - CLAN_D->clan_query( ob1, "member_gold" ) );
}

int sort_develop(string ob1, string ob2)
{
	return ( CLAN_D->clan_query(ob2,"develop")+CLAN_D->clan_query(ob2,"weapon")+CLAN_D->clan_query(ob2,"armor_tech") ) -
	       ( CLAN_D->clan_query(ob1,"develop")+CLAN_D->clan_query(ob1,"weapon")+CLAN_D->clan_query(ob1,"armor_tech") );
}

int sort_war( string ob1 , string ob2 )
{
	return ( CLAN_D->clan_query(ob2,"win") - CLAN_D->clan_query(ob2,"lose") ) -
	       ( CLAN_D->clan_query(ob1,"win") - CLAN_D->clan_query(ob1,"lose") );
}

int main(object me)
{
	int clan_sum, o=0, i, score;
	string clan_name,clan_id,top,list,sort,gate,*money,*war,*develop,*area,*clan_idt,*prestige,*member;

	clan_idt = CLANV_D->fs_clan();
	clan_sum = sizeof(clan_idt);
	war      = sort_array( clan_idt, "sort_war"    , this_object() );
	money    = sort_array( clan_idt, "sort_money"  , this_object() );
	develop  = sort_array( clan_idt, "sort_develop", this_object() );
	area     = sort_array( clan_idt, "sort_area"   , this_object() );
	member   = sort_array( clan_idt, "sort_member" , this_object() );

	list = sprintf(HIC"\n     　幫派名稱        "NOR + CYN"英文名稱        "HIW+
		"幫主            "+HIY"人數   "HIG"簡介   "HIR"閘門\n"NOR +
		"      ====================================================================\n"NOR);

	for( o=0 ; o<clan_sum; o++ )
		CLAN_D->clan_set( clan_idt[o], "score", 0 );

	for( o=0 ; o<clan_sum ; o++ )	{
		clan_id   = clan_idt[o];
		clan_name = CLAN_D->clan_query(clan_id,"name");

		switch( CLAN_D->clan_query( clan_id, "gate_level" ) ) {
		case 1 : gate = "    "; break;
		case 2 : gate = "幫眾"; break;
		case 3 : gate = "盟友"; break;
		case 4 : gate = "開放"; break;
		default  : gate = "----"; break;
		}

		list = sprintf("%s"HIC"     　%-16s"NOR + CYN"%-16s"HIW"%-16s"HIY"%4d" +
			HIG"%6s"HIR"%8s"NOR"\n",
			list,
			clan_name,
			clan_id,
			CLAN_D->clan_query(clan_id,"master"),
			sizeof(CLAN_D->clan_query(clan_id,"members")),
			file_size("/doc/help/clan/"+clan_name)>0 ? "有" : "  ",
			gate
			);

		for( i=0; i<clan_sum; i++ ) {
// 理想的影響力設定: 威望[10] > 戰績[9] > 財產[8] > 地盤[7] > 人數[6]
// 但由於威望和戰積的設定尚未完備
// 因此目前影響力設定: 戰績[9](無) > 財產[8] > 地盤[7] > 人數[6] > 威望[5]
//			if( war[o]==clan_idt[i] )
//				CLAN_D->add_clanset( clan_idt[i], "score", (clan_sum-o)*9 );
			if( money[o]==clan_idt[i] )
				CLAN_D->add_clanset( clan_idt[i], "score", (clan_sum-o)*8  );
			if( develop[o]==clan_idt[i] )
				CLAN_D->add_clanset( clan_idt[i], "score", (clan_sum-o)*5  );
			if( area[o]==clan_idt[i] )
				CLAN_D->add_clanset( clan_idt[i], "score", (clan_sum-o)*7  );
			if( member[o]==clan_idt[i] )
				CLAN_D->add_clanset( clan_idt[i], "score", (clan_sum-o)*6  );
		}
	}

	prestige = sort_array( clan_idt , "sort_prestige" , this_object());
	score = CLAN_D->clan_query( prestige[0] , "score" );
	for( i=0; i<clan_sum; i++ ) { //檢查哪一幫派的威望最高, 賞錢用
		if( CLAN_D->clan_query( prestige[i], "score") == score )
			CLAN_D->clan_set( prestige[i], "prestige_best" , 1 );
		else
			CLAN_D->clan_set( prestige[i], "prestige_best" , 0 );
	}

	sort = sprintf(HIM"\n\t\t     ._______"HIW"ＦＳ"NOR"目前共有 "HIW"%d "NOR"個幫派"HIM"_______.\n\n"+
		HIW"\t\t\t      幫派龍頭 - %s\n\n"
		HIR"  幫派戰績排行榜"NOR" -   "HIY" 幫派財產排行榜 "NOR"-   "HIC" 幫派威望排行榜 "NOR"-   "HIG" 幫派區域排行榜 "NOR"-\n"+
		" ==================  ==================  ==================  ==================\n",
		clan_sum, CLAN_D->clan_query(prestige[0],"name") );
	for( i=0; i<clan_sum; i++ ) {
		sort += sprintf("  ("HIY"%2d"NOR") "HIC"%-13s "NOR" ("HIY"%2d"NOR") "HIC"%-13s "NOR" ("HIY"%2d"NOR") "HIC"%-13s "NOR" ("HIY"%2d"NOR") "HIC"%-13s"NOR"\n",
		i+1, CLAN_D->clan_query(    war[i],"name"), i+1, CLAN_D->clan_query(money[i],"name"),
		i+1, CLAN_D->clan_query(develop[i],"name"), i+1, CLAN_D->clan_query( area[i],"name"),
		);
	}
	me->start_more( sort + list + sprintf(NOR) );
	return 1;
}

int help( object me )
{
	write("
	c_list     : 狂想空間幫派總覽。

	幫派戰績排行榜: 依幫派戰績表現而定。
	幫派財產排行榜: 依幫派錢莊存款多寡而定。
	幫派威望排行榜: 依幫派威望而定。
	幫派區域排行榜: 依幫派勢力範圍, 地盤大小而定。

	幫派龍頭評選標準:

		影響力: 威望 > 戰績 > 財產 > 地盤 > 人數

                                                         by ACKY 2000/02/23
");
        return 1;
}


