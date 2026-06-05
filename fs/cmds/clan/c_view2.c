// 幫派指令集 cview 幫派之能力排行榜暨職位一覽表 by ~babe~ (小雪球) ^O^

#include <ansi.h>
inherit F_CLEAN_UP;

void second( object *user , string str );
string area( object me );
int sort_rank(object ob1, object ob2);
int sort_exp(object ob1, object ob2);
int help( object me );

int main( object me, string str )
{
	object  *user;
	if( !str )
		if( me->query("clan") )
			str = me->query("clan/name");
                else
                        return help(me);

        user = filter_array(users(), "filter_clan", this_object(), str);
        user = sort_array(user, "sort_exp",  this_object());
	second( user , str );
	return 1;
}

void second( object *user , string str )
{
	int     i, count, state;
	string  list, CO, state_str, list2;
	user = sort_array(user, "sort_rank", this_object());
        i = sizeof(user);
        list = sprintf( HIG + "《" + HIY + "%|10s" + HIG + "》" + HIC + " 線上幫眾 " + NOR + "-\n", str );
	list+= "───────────────────────────────────────\n";
	count = 0;

        while( i-- )
        {
                switch(user[i]->query("clan/rank")) {
	case 1  :       CO = HIW + "Ψ";        break;
	case 2  :       CO = HIC + "ζ";        break;
        case 3  :       CO = HIY + "Φ";        break;
        case 4  :       CO = HIG + "卍";        break;
        case 5  :       CO = HIM + "Ξ";        break;
        case 6  :       CO = HIB + "Π";        break;
        case 7  :       CO = HIR + "Χ";        break;
		default :       CO = NOR + "？";        break;
		}

        if(this_player())
        if( wizardp(user[i]) && !wizardp(this_player()))
			continue;
		if( wiz_level(this_player())<6 && user[i]->query("env/隱身") && wiz_level(user[i]) && wiz_level(user[i]) > wiz_level(this_player()) )
		{
		 continue;
		}
		state = 0;
		state_str = "";
		count++;

                list = sprintf( "%s" + HIC + "【" + NOR + "%|10s" + HIC + "】" + NOR + "%s%|10s%s" + NOR + "",
			list,
                        area(user[i]),
                        CO,
                        (user[i]->query("clan/title") ? user[i]->query("clan/title") : "--無職銜--"), CO );
/*
		list2 = (user[i]->query("title") ? user[i]->query("title") : "" ) +
                        (user[i]->query("nickname") ? "「"+user[i]->query("nickname")+"」" : " " ) +
                        user[i]->query("name")+"("+user[i]->query("id")+")";
                if( strlen((list2))>80 )*/
                	list2 = (user[i]->query("nickname") ? "「"+user[i]->query("nickname")+"」" : " " ) +
                        	user[i]->query("name")+"("+user[i]->query("id")+")";
                list += list2;

		if( user[i]->query_temp("netdead") ) {
			state_str += HIR + "(斷線)" + NOR;
			state = 1;
		}
		if( !environment(user[i]) ) {
			state_str += HIG + "(異次元)" + NOR;
			state = 1;
		}
		if( in_edit(user[i]) ) {
			state_str += HIY + "(編輯)" + NOR;
			state = 1;
		}
		if( in_input(user[i]) ) {
			state_str += HIC + "(閱\讀)" + NOR;
			state = 1;
		}
		if( interactive(user[i]) && query_idle(user[i])>120 ) {
                	state_str += sprintf( "%s", HIM + "(發呆 "+query_idle(user[i])/60+" 分鐘)" + NOR );
                	state = 1;
                }
                if( state ) list = list + /*"\t\t\t　　 " +*/ state_str;
                list += "\n";
        }

	list +=	"───────────────────────────────────────\n";
	list += sprintf( " 目前線上共有 %d 位幫眾, 系統負擔: %s\n\n", count, query_load_average() );

        this_player()->start_more(list);
}

int help( object me )
{
	write("
	c_view <幫派名稱>

	顯示線上某幫派之能力排行榜暨職位一覽表。

	              １２３４５６７
	階級顏色說明：" + HIW+"■" + HIC+"■" + HIY+"■" + HIG+"■" + HIM+"■" + HIB+"■" + HIR+"■" + NOR + "


	相關查詢指令: c_who, c_state, c_list

                                                      by ACKY 03/27/00

");
	return 1;
}

string area( object me )
{
	int i;
	string path, tmp;

	if( environment(me) ) {
		if( CLAN_D->what_clan_area(me) == me->query("clan/id") )
			return "本幫地盤";
		path = file_name(environment(me));
	}
	else
		return "異 次 元";

	i = 6;
		while( i++ )
        {
          if(i >= sizeof(path)) break;
          if(path[i])
			if( path[i] == '/' ) {
				tmp = path[6..i-1];
				break;
			}
        }
	switch( tmp )
	{
	case "badman"	: return "惡 人 谷";
	case "beggar"	: return "丐　　幫";
	case "bonze"	: return "少 林 寺";
	case "capital"  : return "京　  城";
	case "center"	: return "中央驛站";
	case "clan"	: return "幫派地盤";
	case "dancer"	: return "鏡 月 島";
	case "doctor"	: return "銀 針 門";
	case "death" 	: return "地　  獄";
	case "fire-hole": return "火龍幻界";
	case "gblade"	: return "金 刀 門";
	case "god"	: return "天　  界";
	case "gsword"	: return "蜀 中 城";
	case "hall"	: return "總理衙門";
	case "killer"	: return "殺手區域";
	case "love"	: return "絕 情 門";
	case "marksman" : return "長 沙 鎮";
	case "mogi"  	: return "魔　  界";
	case "mulitpk"	: return "武鬥會場";
	case "newhand"  : return "新手區域";
	case "ping"	: return "平 南 城";
	case "poison"   : return "冥蠱魔教";
	case "port"	: return "楓 林 港";
	case "prayer"	: return "聖 火 教";
	case "scholar"	: return "儒　　門";
	case "snow"	: return "雪 蒼 派";
	case "start"	: return "凌 雲 村";
	case "steeple"	: return "試 煉 塔";
	case "tailong"	: return "天 龍 寺";
	case "tendo"	: return "天 道 派";
	case "wind-rain": return "金風細雨樓";
	case "wiz"	: return "神　　界";
	case "wu"	: return "正晴武館";
	default		: return "人　　間";
	}
}

int filter_clan(object ob, string name)
{
        if( ob->query("clan/name") == name )
                return 1;
        return 0;
}

int sort_rank(object ob1, object ob2)
{
	return ob2->query("clan/rank") - ob1->query("clan/rank");
}

int sort_exp(object ob1, object ob2)
{

	return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");
}
