// c_state by ACKY 04/13/00

#include <ansi.h>
inherit F_CLEAN_UP;

string get_rank_list( string id, int rank )
{
	string *list;
	int i;

	list = CLAN_D->clan_query(id, "level"+rank);
	if( !i = sizeof(list) )
		return "無";
	id = "";
	while(i--) {
		if( i==sizeof(list)-5 )
			id += "\n\t\t  ";
		id += list[i];
		if(i) id += "，";
		else id += "。";
	}
	return id;
}

string level( string id, string str )
{
	int i, level;
	i = CLAN_D->clan_query(id,str);
	for( level=0; i>0; level++ )
		i-= (level)*(level);
	level-=2;
	if( level < 0 )	level = 0;
	return CHINESE_D->chinese_number(level);
}

string ally( string id )
{
	int	i;
	string	ally, *list;

	list = CLAN_D->clan_query( id, "ally" );
	if( !i = sizeof(list) )
		return "無";
	ally = "";
	while(i--) {
		if( i==sizeof(list)-5 )
			id += "\n\t\t　　　";
		if( !CLAN_D->have_clan( list[i] ) ) {
			CLAN_D->clan_set( id, "ally", list-({list[i]}) );
			continue;
		}
		ally += "【" + CLAN_D->clan_query( list[i], "name" ) + "】";
	}
	return ally;
}

string room( string id, string item )
{
	string	room;
	object	ob;

	if( !room = CLAN_D->clan_query( id, item ) )
		return "無";
	if( !ob = find_object(room) )
		return "無";
	return trans_color(ob->short());
}

int main( object me )
{
	string list="", str="無", tmp, id;
	object *glist, ob;
	int i,money,bank,level;

	if( !me->query("clan" ) ) return 0;
	if( wizardp(me) ) {
		if( CLAN_D->what_clan_area(me) == "NULL" )
			return notify_fail( "此處並非幫派區域。\n" );
		id = CLAN_D->what_clan_area(me);
	}
	else {
		if( me->query("clan/rank") > 5 )
			return notify_fail("您無權使用此指令。\n");
		id = me->query("clan/id");
	}

	money  = sizeof(get_dir(CLAN_D->get_clan_dir(me)+"room/"))*20;
	money += sizeof(get_dir(CLAN_D->get_clan_dir(me)+"npc/"))*2;
	money += sizeof(CLAN_D->clan_query(id, "members"))*10;
	money += sizeof(get_dir(CLAN_D->get_clan_dir(me)+"weapon/"))*1;
	money += sizeof(get_dir(CLAN_D->get_clan_dir(me)+"armor/"))*1;
	CLAN_D->clan_set( id, "cost", money );
	if(CLAN_D->clan_query(id,"alert"))
		str="警戒中";

	list+=sprintf(HIM + "\n	　　.__________" + HIY + "%s(%s)狀態一覽表" + HIM + "__________.\n\n",me->query("clan/name"), id );
	list+=sprintf(HIW + "□ 人事 -\n");
	list+=sprintf(HIW + "	階級- １：" + NOR + "%s。\n",CLAN_D->clan_query(id, "master"));
	list+=sprintf(HIW + "	階級- ２：" + NOR + "%s\n",get_rank_list(id, 2));
	list+=sprintf(HIW + "	階級- ３：" + NOR + "%s\n",get_rank_list(id, 3));
	list+=sprintf(HIW + "	階級- ４：" + NOR + "%s\n",get_rank_list(id, 4));
	list+=sprintf(HIW + "	玩家人數：" + NOR + "%4d人\n",sizeof(CLAN_D->clan_query(id, "members")));
	list+=sprintf(HIW + "	幫眾人數：" + NOR + "%4d人\n\n",sizeof(get_dir(CLAN_D->get_clan_dir(me)+"npc/")));
	list+=sprintf(HIY + "□ 財務 -\n");
	list+=sprintf(HIY + "	幫派存款總額：" + NOR + "共計黃金%10d兩\n",CLAN_D->clan_query(id,"gold"));
	i = CLAN_D->clan_query(id,"member_gold")/(CLAN_D->clan_query(id,"gold")/100+1);
	if( i > 100 )
		i = 100;
	list+=sprintf(HIY + "	幫眾存款比率：" + NOR + "佔總存款%10d％\n", i );
	list+=sprintf(HIY + "	幫派目前稅率：" + NOR + "每回徵收%10d％\n",CLAN_D->clan_query(id,"tax"));
	money = 0;
	glist=users();
	for(i=0;i<sizeof(users());i++)
		if( glist[i]->query("clan/id") == id )	{
			bank = glist[i]->query("bank/coin");
			if( bank > 0 )
				money += bank/10000*CLAN_D->clan_query(id,"tax")/100;
		}
	list+=sprintf(HIY + "	此次徵得稅收：" + NOR + "共計黃金%10d兩\n", money );
	list+=sprintf(HIY + "	幫派目前關稅：" + NOR + "每回黃金%10d兩\n",CLAN_D->clan_query(id,"gatetax"));
	list+=sprintf(HIY + "	幫派基本開銷：" + NOR + "每月黃金%10d兩\n",CLAN_D->clan_query(id,"cost"));
	list+=sprintf(HIY + "	幫派發展經費：" + NOR + "每月黃金%10d兩\n\n",CLAN_D->clan_query(id,"prestige"));
	list+=sprintf(HIG + "□ 發展 -\n");
	list+=sprintf(HIG + "	幫派威望：" + NOR + "%6s級\n\n",level(id,"develop") );
	list+=sprintf(HIC + "□ 區域 -\n");
	list += sprintf(HIC + "\t區域規模: " + NOR + "%d\n", sizeof(get_dir("/open/clan/"+id+"/room/")) );
	list += HIC + "\t幫派核心: " + NOR + room( id, "home" );
	list += HIC + "\n\t幫派錢莊: " + NOR + room( id, "bank" );
	list += HIC + "\n\t幫派兵營: " + NOR + room( id, "npc_room" );
	list += HIC + "\n\t幫派閘門: " + NOR + room( id, "gate" );
	list += HIC + "\n\t幫派監獄: " + NOR + room( id, "jail" );
	list+=sprintf(HIR + "\n\n□ 外交 -\n");
	list+=sprintf(HIR + "	同盟友好幫派：" + NOR + "%s\n", ally( id ) );
	list+=sprintf(HIR + "	幫派警戒狀態：" + NOR + "%s\n",str);
	list+=sprintf(HIR + "	幫派戰勝次數：" + NOR + "%s回\n",CHINESE_D->chinese_number(CLAN_D->clan_query(id,"win")) );
	list+=sprintf(HIR + "	幫派戰敗次數：" + NOR + "%s回\n",CHINESE_D->chinese_number(CLAN_D->clan_query(id,"lose")) );
	me->start_more(list);
	return 1;
}

int help( object me )
{
	write("\n   c_state    ：幫派狀況總覽。

");
        return 1;
}
