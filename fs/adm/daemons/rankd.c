// rankd.c

#include <ansi.h>

mapping wiz_rank = ([
	"(admin)": 		({ HIW "【 天  帝 】" NOR, HIW "【 天  后 】" NOR }),
	"(arch)": 		({ HIY "【 天  帝 】" NOR, HIY "【 天  后 】" NOR }),
	"(wizard)": 	({ HIG "【 天  帝 】" NOR, HIG "【 天  后 】" NOR }),
	"(apprentice)":	({ HIC "【 天  帝 】" NOR, HIC "【 天  后 】" NOR }),
]);

string query_rank(object ob)
{
	string level="";
	string guild="";
	if( ob->is_ghost() ) return HIB "【 鬼  魂 】" NOR;
	if( ob->query("class") ) guild=ob->query("class");
	if(ob->query("class_level")) level="-"+ob->query("class_level");
	if(ob->query("gender")=="女性")
	{
		if(wizhood(ob)!="(player)")
			return to_chinese("f_"+wizhood(ob));
		if(!ob->query("class_level"))
		  if(!ob->query("class")) return "【 平  民 】" NOR;
		    return to_chinese("f_"+guild+level);
	}
	else
	{
		if(wizhood(ob)!="(player)")
			return to_chinese(wizhood(ob));
		if(!ob->query("class_level"))
		  if(!ob->query("class")) return "【 平  民 】" NOR;
		    return to_chinese(guild+level);
	}
}

// 平時稱對方
string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小師太";
				else return "師太";
				break;
			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";
				break;
			case "officer":
				return "大人";
				break;
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "婆婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小師父";
				else return "大師";
				break;
			case "taoist":
				if( age < 18 ) return "道兄";
				else return "道長";
				break;
			case "officer":
					return "大人";
					break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 50 ) return "壯士";
				else return "老前輩";
				break;
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 50 ) return "壯士";
				else return "老爺子";
				break;
			}
	}
}

// 戰時稱敵人
string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				return "賊尼";
				break;
			case "taoist":
				return "妖女";
				break;
			case "officer":
				return "朝廷的走狗";
				break;
			default:
				if( age < 30 ) return "小賤人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "死禿驢";
				else return "老禿驢";
				break;
			case "taoist":
				return "死牛鼻子";
				break;
			case "officer":
				return "朝廷的走狗";
				break;
			default:
				if( age < 20 ) return "小王八蛋";
				if( age < 50 ) return "臭賊";
				else return "老匹夫";
				break;
			}
	}
}

// 平時自稱
string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "貧尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "小女子";
				if( age >=30 && age < 50 ) return "妾身";
				else return "老身";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "貧僧";
				else return "老納";
				break;
			case "taoist":
				return "貧道";
				break;
			default:
				if( age < 50 ) return "在下";
				else return "老頭子";
				break;
			}
	}
}

// 戰鬥時自稱
string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "貧尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "本姑娘";
				else return "老娘";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "taoist":
				return "本山人";
				break;
			default:
				if( age < 50 ) return "大爺我";
				else return "老子";
				break;
			}
	}
}
