// skills.c

#include <ansi.h>
inherit F_CLEAN_UP;

string *skill_level_desc = ({
	BLU + "初學乍練" + NOR,
	HIB + "粗通皮毛" + NOR,
	HIB + "半生不熟" + NOR,
	HIB + "馬馬虎虎" + NOR,
	HIB + "駕輕就熟" + NOR,
	CYN + "出類拔萃" + NOR,
	CYN + "神乎其技" + NOR,
	CYN + "出神入化" + NOR,
	HIC + "登峰造極" + NOR,
	HIC + "一代宗師" + NOR,
	HIW + "深不可測" + NOR
});

string *knowledge_level_desc = ({
	BLU + "新學乍用" + NOR,
	HIB + "初窺門徑" + NOR,
	HIB + "略知一二" + NOR,
	HIB + "馬馬虎虎" + NOR,
	HIB + "已有小成" + NOR,
	CYN + "心領神會" + NOR,
	CYN + "了然於胸" + NOR,
	CYN + "豁然貫通" + NOR,
	HIC + "舉世無雙" + NOR,
	HIC + "震古鑠今" + NOR,
	HIW + "深不可測" + NOR
});

string skill_level(string, int);

void create() { seteuid(getuid()); }
varargs int main( object me, string arg, int mode )
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped;
	int i;


	if(!arg)
		ob = me;
	else {
	  arg = lower_case(arg);
	  ob = present(arg, environment(me));
// Modify By Chun 09.22.1996 
//因為若無此人會增加error message 到debug.log,故做此修正
        if( wizardp(me) ) {
              arg = lower_case(arg);
              ob = present( arg, environment(me) );
              if( !ob )
                      ob = find_player(arg);
              if( !ob )
                      ob = find_living(arg);
              if( !ob )
                      ob = FINGER_D->acquire_login_ob(arg);
              if( !ob )
                      return notify_fail("你要察看誰的狀態?\n");
        }

	  if( !ob && !wizardp(me) ) return notify_fail("這裡沒這個人。\n");

	}

// Modify By Spirits. 10.02.1995
	if ( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me) &&
		!ob->query("guild_master") &&
		!me->is_apprentice_of(ob) )
	{
	  return notify_fail("只有巫師或有師徒關係的人能察看他人的技能。\n");
	}

// Modify By ICE 10.19.1995
// 不想讓 player 看到 wizard 的 skills..
// fixed by wade 1/4/1996

	if (wizardp(ob) && !wizardp(me))
	  return notify_fail("你不可以偷看巫師的技能。\n");

	if( mode==1 )
		ob = me->query_temp("pal");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前並沒有學會任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前所學過的技能﹕\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
        if (file_size("daemon/skill/"+sname[i]+".c") == -1 && !wiz_level(me))
			ob->delete_skill(sname[i]);
		else
		printf("%s%s%-40s" + NOR + " - %-10s %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "ˇ"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 10;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : skills [<某人>]
指令說明 :
           這個指令可以讓你(妳)查詢所學過的技能。
           你也可以指定一個和你有師徒關係的對象﹐用 skills
           可以查知對方的技能狀況。
           巫師可以查詢任何人或 NPC 的技能狀況。
HELP
    );
    return 1;
}


