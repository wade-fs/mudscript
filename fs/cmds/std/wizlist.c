// wizlist.c

inherit F_CLEAN_UP;
#include <ansi.h>
string popu(int level)
{
  switch(level)
  {
    case 0..9:
      return MAG;
      break;
    case 10..35:
      return WHT;
    break;
    case 36..300:
      return HIW;
    break;
    case 301..1000:
      return HIR;
    break;
    default:
      return HIM;
  }
}
int main(object me, string arg)
{
	string *list;
	int my_level, i, j;
	int ch;
	object ob;
  int update; 
  seteuid(ROOT_UID);
	list = sort_array(SECURITY_D->query_wizlist(), 1);
   write(MUD_NAME + "目前的天神地鬼一共有 "+ (sizeof(list)-1) + " 位﹕(前面有 * 者表正在線上)\n");
	my_level=wiz_level(me);
        printf("----------------------------    "+HIW+" 天帝        地皇"+NOR+"   ----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(manager)")
	{
    update = "/adm/daemons/wizardd"->query(list[i]+"/week");
		ch = ' ';
		if(ob=find_player(list[i]))
			if(wizardp(me))
			if(!ob->query("env/隱身") || wiz_level(ob) <= my_level)
				ch = '*';
		printf("%c%s%-10s%s"NOR, ch, popu(update),list[i] ,((j++)%7==6) ? "\n  " : "");
	}
        printf("\n----------------------------  "+HIM+"混世魔王    羅煞女王  "+NOR+"----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(guest)")
	{
    update = "/adm/daemons/wizardd"->query(list[i]+"/week");

		ch = ' ';
		if(ob=find_player(list[i]))
			if(wizardp(me))
			if(!ob->query("env/隱身") || wiz_level(ob) <= my_level)
				ch = '*';
		printf("%c%s%-10s%s"NOR, ch, popu(update),list[i] ,((j++)%7==6) ? "\n  " : "");

	}
printf("\n----------------------------    "+HIC+"玉帝       修羅王"+NOR+"   ----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(admin)")
	{
    update = "/adm/daemons/wizardd"->query(list[i]+"/week");

		ch = ' ';
		if(ob=find_player(list[i]))
			if(wizardp(me))
			if(!ob->query("env/隱身") || wiz_level(ob) <= my_level)
				ch = '*';
		printf("%c%s%-10s%s"NOR, ch, popu(update),list[i] ,((j++)%7==6) ? "\n  " : "");
	}
        printf("\n----------------------------    "+HIY+"菩薩       夜叉王   "+NOR+"----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(arch)")
	{
    update = "/adm/daemons/wizardd"->query(list[i]+"/week");

		ch = ' ';
		if(ob=find_player(list[i]))
			if(wizardp(me))
			if(!ob->query("env/隱身") || wiz_level(ob) <= my_level)
				ch = '*';
		printf("%c%s%-10s%s"NOR, ch, popu(update),list[i] ,((j++)%7==6) ? "\n  " : "");

	}
        printf("\n----------------------------    "+HIG+"天仙        判官"+NOR+"    ----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(wizard)")
	{
    update = "/adm/daemons/wizardd"->query(list[i]+"/week");

		ch = ' ';
		if(ob=find_player(list[i]))
			if(wizardp(me))
			if(!ob->query("env/隱身") || wiz_level(ob) <= my_level)
				ch = '*';
		printf("%c%s%-10s%s"NOR, ch, popu(update),list[i] ,((j++)%7==6) ? "\n  " : "");
	}
        printf("\n----------------------------    "+HIR+"護法        無常"+NOR+"    ----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(apprentice)")
	{
    update = "/adm/daemons/wizardd"->query(list[i]+"/week");

		ch = ' ';
		if(ob=find_player(list[i]))
			if(wizardp(me))
			if(!ob->query("env/隱身") || wiz_level(ob) <= my_level)
				ch = '*';
		printf("%c%s%-10s%s"NOR, ch, popu(update),list[i] ,((j++)%7==6) ? "\n  " : "");
	}
        printf("\n----------------------------  "+HIB+"天兵天將    牛頭馬面"+NOR+"  ----------------------------\n  ");
	for(i=0, j=0; i<sizeof(list); i++)
	if(SECURITY_D->get_status(list[i])=="(immortal)")
		printf("%c%s%-10s%s"NOR, (find_player(list[i])) ? ch:' ', popu(update) ,list[i], ((j++)%7==6) ? "\n  " : "");
	write("\n\n");
  printf("  說明：%s無活動%s/%s少量活動%s/%s大量活動%s/%s沒事就動%s/%s用機器人寫程式%s\n",
      popu(0),NOR,
      popu(11),NOR,
      popu(37),NOR,
      popu(301),NOR,
      popu(3000),NOR
      );
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : wizlist
指令說明 :
           本指令用來查看目前狂想空間總共有多少個巫師。
HELP
    );
    return 1;
}
