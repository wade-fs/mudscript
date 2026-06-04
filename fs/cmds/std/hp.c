// hp cmds

#include <ansi.h>

inherit F_CLEAN_UP;

string status_color(int current, int max);
string score_string(object ob);
string hero_string(object ob);

varargs int main( object me, string arg, int mode )
{
        object ob;
        mapping my;
        string status_desc="";

        seteuid(getuid(me));

        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看誰的狀態﹖\n");
        } else
                return notify_fail("只有巫師能察看別人的狀態。\n");

	if( mode==1 )
		ob = me->query_temp("pal");

        my = ob->query_entire_dbase();

	printf( "精力:%s%6d /%6d (%3d%%)" + NOR+
                "  靈力:%s%6d /%6d (+%2d)" + NOR+
                "  饑餓/口渴: %s%d%% / %s%d%%\n" + NOR,
		status_color( my["gin"], my["max_gin"] ),
		my["gin"],
		my["eff_gin"],
		my["eff_gin"] * 100 / my["max_gin"],
		status_color( my["atman"], my["max_atman"] ),
                my["atman"], my["max_atman"],
                my["atman_factor"],
                status_color(my["food"], ob->max_food_capacity()),
                100-100*my["food"]/ob->max_food_capacity(),
                status_color(my["water"], ob->max_water_capacity()),
                100-100*my["water"]/ob->max_water_capacity() );
	printf( "氣血:%s%6d /%6d (%3d%%)" + NOR+
                "  內力:%s%6d /%6d (+%2d)" + NOR+
                "  潛在-能力: %O(%O%%)\n" + NOR,
                status_color( my["kee"], my["max_kee"]),
                my["kee"], my["eff_kee"],
                my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),
                my["force"], my["max_force"],
                my["force_factor"],
                (int)ob->query("potential") - (int)ob->query("learned_points"),
                (1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")));
	printf( "神瞑:%s%6d /%6d (%3d%%)" + NOR + "  法力:%s%6d /%6d (+%2d)" + NOR + "  實戰-經驗: %O\n",
                status_color(my["sen"], my["max_sen"]),
                my["sen"], my["eff_sen"],
                my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
                my["mana_factor"],
                my["combat_exp"] );

	status_desc += CON_D->con_query(ob);
        status_desc += (ob->query_temp("medicine/plaster_power")?"[1;33m(塗藥)[0m ":"");
        status_desc += (ob->query_temp("sun-moon")?"(" + HIY + "昊玥氣勁" + NOR + ") ":"");
        status_desc += (ob->query_temp("bloodkee")?"(" + HIR + "血殺餘勁" + NOR + ") ":"");
        status_desc += (ob->query_temp("bloodfight")?"(" + HIR + "血魔鬥氣" + NOR + ") ":"");
        status_desc += (ob->query_temp("no_power_sword")?"(" + HIY + "涅盤殺勁" + NOR + ") ":"");
        status_desc += (ob->query_temp("no_power_godsub")?"(" + HIC + "分身餘勁" + NOR + ") ":"");
        status_desc += (ob->query_temp("medicine/bandaged")?"[1m(包紮)[0m ":"");
        if(ob->query_temp("not_robot") > time()  ) 
        {
          if(ob->query_temp("not_robot") - time() < 60 * 5 ){
            status_desc += WHT + "(太極內力"
              +((wizardp(me)) ? " - "+  (int)((ob->query_temp("not_robot") - time()) / 60)+" 分鐘" : "")
              +")" + NOR;
          } else {
            status_desc += WHT + "(" + HIB + "太" + HIW + "極" + HIB + "內" + HIW + "力" + WHT
              +((wizardp(me)) ? " - "+  (int)((ob->query_temp("not_robot") - time()) / 60)+" 分鐘" : "")
              +")" + NOR;
          }
        }
        if( status_desc=="" ) status_desc += "無";
	printf("名聲: %s              殺氣:" + HIR + "%6d"+NOR+"                武學-修為: %s\n",score_string(ob),my["bellicosity"],hero_string(ob));
	printf("狀態: %s\n", status_desc );
	return 1;
}

string status_color( int current, int max )
{
        int ratio;

        if( max>0 )
        	ratio = current * 100 / max;
        else
        	ratio = 100;
	if( ratio >100 ) return HIC;
        if( ratio > 90 ) return HIG;
        if( ratio > 80 ) return GRN;
        if( ratio > 60 ) return HIY;
        if( ratio > 40 ) return YEL;
        if( ratio > 20 ) return HIR;
		         return RED;
}

string score_string(object ob)
{
  int scores;
  string *ppl_desc;

  scores =scores+(ob->query("MKS")*2);
  scores =scores-(ob->query("PKS")*500);
  scores =scores-(ob->query("death/time")*300);
  scores =scores+(ob->query("pk_win")*40);
  scores =scores-(ob->query("pk_lose")*40);
  scores =scores+(ob->query("scores"));

       ppl_desc=({
        HIR + "邪魔轉世" + NOR,
        HIR + "惡貫滿盈" + NOR,
        HIR + "罪大惡極" + NOR,
        HIM + "殺人如麻" + NOR,
        HIM + "無惡不做" + NOR,
        HIC + "惡名昭彰" + NOR,
        HIC + "略帶邪氣" + NOR,
        NOR + "無名小卒" + NOR,
        HIG + "心存向善" + NOR,
        HIG + "慈悲為懷" + NOR,
        HIG + "略有俠名" + NOR,
        HIW + "仗義為人" + NOR,
        HIW + "再世高人" + NOR,
        HIY + "俠名遠播" + NOR,
        HIY + "一代大俠" + NOR,
        });

        if(scores <= -6000 )
                return ppl_desc[0];
      else if(scores <= -5000)
                return ppl_desc[1];
      else if(scores <= -4000)
                return ppl_desc[2];
      else if(scores <= -3000)
                return ppl_desc[3];
      else if(scores <= -2000)
                return ppl_desc[4];
      else if(scores <= -1000)
                return ppl_desc[5];
      else if(scores <= -500)
                return ppl_desc[6];
      else if(scores <= 500)
                return ppl_desc[7];
      else if(scores <= 1000)
                return ppl_desc[8];
      else if(scores <= 2000)
                return ppl_desc[9];
      else if(scores <= 3000)
                return ppl_desc[10];
      else if(scores <= 4000)
                return ppl_desc[11];
      else if(scores <= 5000)
                return ppl_desc[12];
      else if(scores <= 6000)
                return ppl_desc[13];
      else return ppl_desc[14];

}
string hero_string(object ob)
{
  int exp;
  string *ppl_desc;
  exp=ob->query("combat_exp");
  ppl_desc=({
        RED + "初窺門道" + NOR,
        HIR + "心領神會" + NOR,
        HIR + "應用自如" + NOR,
        BLU + "身經百戰" + NOR,
        HIB + "技壓群雄" + NOR,
        HIB + "萬夫莫敵" + NOR,
        MAG + "宏遠無儔" + NOR,
	HIM + "隨心所欲" + NOR,
	GRN + "出神入化" + NOR,
	HIG + "驚世駭俗" + NOR,
	YEL + "武道大成" + NOR,
	HIY + "成宗立派" + NOR,
	CYN + "登峰造極" + NOR,
	HIC + "舉世無雙" + NOR,
	HIW + "學究天人" + NOR,
	HIC + "武天至聖" + NOR,
	HIW + "天人合一" + NOR,
       "[1;30m傳說之神話" + NOR
  });

        if(exp <= 100000)
                return ppl_desc[0];
   else if(exp <= 300000)
                return ppl_desc[1];
   else if(exp <= 600000)
                return ppl_desc[2];
   else if(exp <= 1000000)
                return ppl_desc[3];
   else if(exp <= 1500000)
                return ppl_desc[4];
   else if(exp <= 2000000)
                return ppl_desc[5];
   else if(exp <= 3000000)
                return ppl_desc[6];
   else if(exp <= 4000000)
                return ppl_desc[7];
   else if(exp <= 5000000)
                return ppl_desc[8];
   else if(exp <= 6000000)
                return ppl_desc[9];
   else if(exp <= 7000000)
                return ppl_desc[10];
   else if(exp <= 8000000)
                return ppl_desc[11];
   else if(exp <= 9000000)
                return ppl_desc[12];
   else if(exp <=10000000)
                return ppl_desc[13];
   else if(exp <=20000000)
                return ppl_desc[14];
   else if(exp <=30000000)
                return ppl_desc[15];
   else if(exp <=40000000)
                return ppl_desc[16];
   else
                return ppl_desc[17];
}


int help(object me)
{
        write(@HELP
指令格式 : hp
           hp <對象名稱>                   (巫師專用)
指令說明 :
           這個指令可以顯示你(妳)或指定對象(含怪物)的
       精，氣，神數值或者其他身體狀況。
其他參考 :
           score
HELP
    );
    return 1;
}
