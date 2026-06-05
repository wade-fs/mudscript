// score.c
// Modify By Spirits.
// Modified by wade 1/10/1996
// Modified by Anmy 98/4/2
// Modified by Chan 98/8/17
//排版 by blazakira 2011/9/2

inherit F_CLEAN_UP;
#include <ansi.h>
#include <combat.h>

string state( int value, int max );
string status_color( int value, int max );
string status_string( int status );

void create() { seteuid(ROOT_UID); }

void wiz_score(object ob)
{
  mapping my;
  string skill_type, couples,attack_skill,skill_map;
  object weapon,master;
  int attack_points, dodge_points, parry_points,damage,damage_bonus,power_dam,damage_1,damage1,damage2,damage_2;
  my = ob->query_entire_dbase();
  if( objectp(weapon = ob->query_temp("weapon")) )
    if(present(weapon, ob))
      skill_type = weapon->query("skill_type");
    else {
      weapon = 0;
      ob->delete_temp("weapon");
      skill_type = "unarmed";
    }
  else skill_type = "unarmed";
  attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
  parry_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_OTHER);
  dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
// 傷害力部分 by swy
  if( objectp(weapon) )  {
    attack_skill = weapon->query("skill_type");
    damage = (int) ob->query_temp("apply/damage");
    if( damage > 500 ) damage = 500;
  }
  else damage = 0;
  skill_map = ob->query_skill_mapped(attack_skill);
  damage += (int)ob->query_skill(attack_skill, 1)*2+(int)ob->query_skill("force", 1);
  if(userp(ob)) {
    if( ob->query_skill(skill_map, 1) != 0 )
      damage += ob->query_skill(skill_map, 1)*3;
    else damage = damage;
  } else {
    if( ob->query_skill(skill_map, 1) != 0 )
      damage += ob->query_skill(skill_map, 1)*2;
    else damage = damage;
  }
// 加上 skills 裡的 damage by swy
  if( my["class"]=="fighter" ) {
    damage += 500; }
  else if(my["class"]=="swordsman"||my["class"]=="blademan"||my["class"]=="bandit") {
    damage += 400; }
  else if(my["class"]=="scholar"||my["class"]=="prayer"||my["class"]=="bonze"||
      my["class"]=="beggar"||my["class"]=="officer"||my["class"]=="marksman") {
    damage += 300; }
  else if(my["class"]=="killer"||my["class"]=="poisoner"||my["class"]=="doctor"|| my["class"]=="taoist") {
    damage += 100; }
  else if(my["class"]=="dancer") {
    damage += 200; }
  else {
    damage += 50; }
// 額外傷害力 by swy
//  damage_bonus = my["str"];
  damage_bonus = ob->query_str();
  if( my["class"]=="fighter" ) {
    damage2 = 500; }
  else if(my["class"]=="swordsman"||my["class"]=="blademan"||my["class"]=="bandit") {
    damage2 = 400; }
  else if(my["class"]=="scholar"||my["class"]=="prayer"||my["class"]=="bonze"||
      my["class"]=="beggar"||my["class"]=="officer"||my["class"]=="marksman") {
    damage2 = 300; }
  else if(my["class"]=="killer"||my["class"]=="poisoner"||my["class"]=="doctor"||
      my["class"]=="taoist") {
    damage2 = 100; }
  else if(my["class"]=="dancer") {
    damage2 = 200; }
  else {
    damage2 = 50; }
  damage_bonus+=(int)(my["force_factor"]*damage2*0.15);
// 敵人打你可以抵銷的值 by swy
  power_dam = my["max_force"];
  damage_1 = (int)(power_dam / 10);
// 總傷害力 by swy
  damage1 = damage+damage_bonus+(attack_points/100);
// 總抵銷值 by swy
  damage_2 = damage_1+(dodge_points/100)+(parry_points/100);

  printf( BOLD + "%s" + NOR + "%s\n" + "□ 生日：%s\n□ 年齡：%s歲\t性別：%s\n",
      RANK_D->query_rank(ob),
      ob->short(),
      CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60),
      chinese_number(my["age"]),
      my["gender"] );
  if (ob->query("couples/id")) {
    if( master=find_player(my["couples"]["id"])) {
      if( master->query("name") != my["couples"]["name"])
        ob->set("couples/name",master->query("name"));
    }
    else {
      if( master=FINGER_D->acquire_login_ob(my["couples"]["id"])) {
        if( master->query("name") != my["couples"]["name"])
          ob->set("couples/name",master->query("name"));
        destruct(master);
      }
    }
    couples = my["couples"]["name"];
    printf( "\t配偶是: %O。\n", couples );
  }

  printf( "□ 總共殺了 " + HIY + "%d" + NOR + " 個人， " + HIR + "%d" + NOR + " 位玩家，其中有 " + HIM + "%d" + NOR + " 位高手。\n",
      my["MKS"] + my["PKS"], my["PKS"], my["HKS"] );
  printf( "□ 戰功\: " + HIY + "%6d" + NOR + "\n",my["war_score"] );
  printf( "□ 狀況﹕%s[0m\n",status_string(my["status"]) );

  if( mapp(my["family"]) ) {
    if( my["family"]["master_name"] ) {
      if( my["family"]["master_is_ppl"] ) {
        if( master=find_player(my["family"]["master_id"])) {
          if( master->query("name") != my["family"]["master_name"])
            ob->set("family/master_name",master->query("name"));
        }
        else {
          if( master=FINGER_D->acquire_login_ob(my["family"]["master_id"])) {
            if( master->query("name") != my["family"]["master_name"])
              ob->set("family/master_name",master->query("name")); 
            destruct(master);
          }
        }
      }
      printf( "□ 門派﹕ " + HIW + "%s" + NOR + "。\t師父：" + HIW + "%s" + NOR + "。\n",my["family"]["family_name"],my["family"]["master_name"] );
    }
  }
  if(my["clan"])
  {
    printf( "□ 所屬幫派："+HIY+"%s\n" + NOR,my["clan"]["name"]);
    if(my["clan"]["title"])
      printf("□ 幫中職位："+HIC+"%s\n\n" + NOR,my["clan"]["title"] );
  }
  if(my["max_s_kee"])
    printf( "□ 靈氣：【 %s 】："+ HIG+"%d/%d\n" + NOR,to_chinese(my["sec_kee"]),my["s_kee"], my["max_s_kee"] );

  if(my["class"] && my["class"]=="officer")
  {
    printf( "□ 官位：【" + HIW + "%s" + NOR + "】\t權力：" + HIY + "%d/%d\n" + NOR + "\t政治經驗：" + HIC + "%d\n" + NOR,
        my["officer_class"],
        my["officer_power"],
        my["max_officer_power"],
        my["office_exp"] );
  }

  printf( "□ 臂力[str]: %2d   膽識[cor]: %2d   悟性[int]: %2d   靈性[spi]: %2d\n"+
          "□ 定力[cps]: %2d   容貌[per]: %2d   根骨[con]: %2d   福緣[kar]: %2d\n\n",
      ob->query_str(), ob->query_cor(), ob->query_int() , ob->query_spi() ,
      ob->query_cps(), ob->query_per(), ob->query_con(), ob->query_kar() );
  printf( "□ 精：%s%8d/%-8d\t%s(%d%%)" + NOR + "\t靈力：%s%8d/%-8d\t(+%d)" + NOR + "\t食物：%s%3d/%3d\n" + NOR,
      status_color(my["gin"], my["eff_gin"]), my["gin"], my["eff_gin"],
      status_color(my["eff_gin"], my["max_gin"]),
      my["eff_gin"] * 100 / my["max_gin"],
      status_color(my["atman"], my["max_atman"]), my["atman"], my["max_atman"],
      my["atman_factor"],
      status_color(my["food"], ob->max_food_capacity()),
      my["food"],
      ob->max_food_capacity() );
  printf( "□ 氣：%s%8d/%-8d\t%s(%d%%)" + NOR + "\t內力：%s%8d/%-8d\t(+%d)" + NOR + "\t飲水：%s%3d/%3d\n" + NOR,
      status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
      status_color(my["eff_kee"], my["max_kee"]),
      my["eff_kee"] * 100 / my["max_kee"],
      status_color(my["force"], my["max_force"]), my["force"], my["max_force"],
      my["force_factor"],
      status_color(my["water"], ob->max_water_capacity()),
      my["water"],
      ob->max_water_capacity() );
  printf( "□ 神：%s%8d/%-8d\t%s(%d%%)" + NOR + "\t法力：%s%8d/%-8d\t(+%d)\n\n" + NOR,
      status_color(my["sen"], my["eff_sen"]),  my["sen"], my["eff_sen"],
      status_color(my["eff_sen"], my["max_sen"]),
      my["eff_sen"] * 100 / my["max_sen"],
      status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
      my["mana_factor"] );

  printf( "□ 戰鬥攻擊力：" + HIW + "%10O(+%O)" + NOR + "\t戰鬥防禦力：" + HIW + "%10O(+%O)\n" + NOR,
      attack_points+1,(int)ob->query_temp("apply/damage"),
      (dodge_points + (weapon? parry_points: (parry_points/10)))+1,(int)ob->query_temp("apply/armor") );
  printf( "□ 武學傷害力：" + HIW + "%10d" + NOR + "\t額外傷害力：" + HIW + "%10d" + NOR + "\t\t總合傷害力：" + HIW + "%10d\n" + NOR,
      damage,damage_bonus,damage1 );
  printf( "□ 內力抵銷值：" + HIW + "%10d" + NOR + "\t總抵銷值  ：" + HIW + "%10d\n" + NOR,
      damage_1,damage_2 );
  printf( "□ 殺      氣：" + RED + "%10O" + NOR + "\t潛      能：" + HIY + "%10O(%O%%)" + NOR + "\t實戰經驗  ：" + HIM + "%10O\n" + NOR,
      my["bellicosity"],
      my["potential"] - my["learned_points"],
      (int)(1 + my["learned_points"]) * 100 /(1 + my["potential"]),
      my["combat_exp"] );
}

void player_score(object ob)
{
  mapping my;
  string skill_type, couples;
  object weapon,master;
  int attack_points, dodge_points, parry_points;

  my = ob->query_entire_dbase();

  printf( BOLD + "%s" + NOR + "%s\n" + "□ 生日：%s\n□ 年齡：%s歲\t性別：%s",
      RANK_D->query_rank(ob),
      ob->short(),
      CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60),
      chinese_number(my["age"]),
      my["gender"] );
  if (ob->query("couples/id")) {
    if( master=find_player(my["couples"]["id"])) {
      if( master->query("name") != my["couples"]["name"])
        ob->set("couples/name",master->query("name"));
    }
    else {
      if( master=FINGER_D->acquire_login_ob(my["couples"]["id"])) {
        if( master->query("name") != my["couples"]["name"])
          ob->set("couples/name",master->query("name")); 
        destruct(master);
      }
    }
    couples = my["couples"]["name"];
    printf( "\t配偶是: %s。\n", couples );
  }
  else
    printf( "。\n" );

  printf( "□ 總共殺了 " + HIC + "%d" + NOR + " 個人， " + HIR + "%d" + NOR + " 位玩家，其中有 " + HIM + "%d" + NOR + " 位高手。\n",
      my["MKS"] + my["PKS"], my["PKS"], my["HKS"] );
  if( my["war_score"] )
    printf( "□ 戰功\: " + HIY + "%d" + NOR + " 點\n", my["war_score"] );
  printf( "□ 狀況﹕%s[0m\n",status_string(my["status"]) );

  if( mapp(my["family"]) ) {
    if( my["family"]["master_name"] ) {
      if( my["family"]["master_is_ppl"] ) {
        if( master=find_player(my["family"]["master_id"])) {
          if( master->query("name") != my["family"]["master_name"])
            ob->set("family/master_name",master->query("name"));
        }
        else {
          if( master=FINGER_D->acquire_login_ob(my["family"]["master_id"])) {
            if( master->query("name") != my["family"]["master_name"])
              ob->set("family/master_name",master->query("name")); 
            destruct(master);
          }
        }
      }
      printf( "□ 門派﹕ " + HIW + "%s" + NOR + "。\t師父：" + HIW + "%s" + NOR + "。\n",my["family"]["family_name"],my["family"]["master_name"] );
    }
  }

  if(my["clan"]) {
    printf( "\n□ 所屬幫派: "+HIY+"%s\n" + NOR,my["clan"]["name" ] );
    if(my["clan"]["title"])
      printf( "□ 幫中職位: "+HIC+"%s\n\n" + NOR,my["clan"]["title"] );
  }

  if(my["max_s_kee"])
    printf("□ 靈氣【 %s 】: "+ HIG+"%d/%d\n" + NOR,to_chinese(my["sec_kee"]),my["s_kee"],my["max_s_kee"] );

  if(my["class"] && my["class"]=="officer")
  {
    printf("□ 官位:【" + HIW + "%s" + NOR + "】 權力 %d/%d  □ 政治經驗: " + HIC + "%d\n" + NOR,
        my["officer_class"],
        my["officer_power"],my["max_officer_power"],
        my["office_exp"] );
  }

  printf( "□ 臂力[str]: %2d   膽識[cor]: %2d   悟性[int]: %2d   靈性[spi]: %2d\n"+
          "□ 定力[cps]: %2d   容貌[per]: %2d   根骨[con]: %2d   福緣[kar]: %2d\n\n",
      ob->query_str(), ob->query_cor(), ob->query_int(), ob->query_spi(),
      ob->query_cps(), ob->query_per(), ob->query_con(), ob->query_kar() );
  printf( "□ 精: %s%s%-6s%s  靈力: %s%-5s  經驗值: " + HIM + "%-12d" + NOR + " 食物: %s  飲水: %s\n" + NOR,
      state( my["gin"], my["eff_gin"] ),
      status_color(my["eff_gin"], my["max_gin"]),
      "("+my["eff_gin"] * 100 / my["max_gin"]+"%)",NOR,
      state (my["atman"], my["max_atman"]),
      "("+my["atman_factor"]+")",
      my["combat_exp"],
      state(my["food"], ob->max_food_capacity()),
      state (my["water"], ob->max_water_capacity()) );

  printf( "□ 氣: %s%s%-6s%s  內力: %s%-5s  潛  能: %-12s " + HIR + "殺氣" + NOR + " %-5d" + HIR + " 中毒" + NOR + " %s\n",
      state (my["kee"], my["eff_kee"]),
      status_color(my["eff_kee"], my["max_kee"]),
      "("+my["eff_kee"] * 100 / my["max_kee"]+"%)",NOR,
      state (my["force"], my["max_force"]),
      "("+my["force_factor"]+")",
      my["potential"] - my["learned_points"]+"("+
        (int)(1+(int)my["learned_points"])*100 / (1+(int)my["potential"])+"%)",
      my["bellicosity"],
      ob->query_condition()?":~~(":NOR + ":-)", );

  if( objectp(weapon = ob->query_temp("weapon")) )
    if (present(weapon, ob))
      skill_type = weapon->query("skill_type");
    else {
      weapon = 0;
      ob->delete_temp("weapon");
      skill_type = "unarmed";
    }
  else
    skill_type = "unarmed";

  attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
  parry_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_OTHER);
  dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

  printf("□ 神: %s%s%-6s%s  法力: %s%-5s \n\n",
      state( my["sen"], my["eff_sen"] ),
      status_color( my["eff_sen"], my["max_sen"] ),
      "("+my["eff_sen"] * 100 / my["max_sen"]+"%)",NOR,
      state (my["mana"], my["max_mana"]),
      "("+my["mana_factor"]+")" );

  printf( HIY + "《戰鬥攻擊力》: " + HIW + "%O(" + HIC + "+%O" + HIW + ")\n" + NOR + HIY + "《戰鬥防禦力》: " + HIW + "%O(" + HIG + "+%O" + HIW + ")\n" + NOR,
      attack_points+1,(int)ob->query_temp("apply/damage"),
      (dodge_points + (weapon? parry_points: (parry_points/10)))+1,
      (int)ob->query_temp("apply/armor") );
}

// by babe
string status_color( int value, int max )
{
  int ratio;

  if( max )
    ratio = value * 100 / max;
  else
    ratio = 100;

  if     ( ratio > 100 ) return HIC;
  else if( ratio ==100 ) return HIW;
  else if( ratio >= 90 ) return HIG;
  else if( ratio >= 80 ) return GRN;
  else if( ratio >= 60 ) return HIY;
  else if( ratio >= 40 ) return YEL;
  else if( ratio >= 20 ) return HIR;
  else                   return RED;
}

// by babe
string state( int value, int max )
{
  int ratio;
  string msg;

  if( max==0 )
    return HIR+"._.??"+NOR;

  ratio  = value * 100 / max;
  if     ( ratio > 100 ) msg = HIC + "*_* ";
  else if( ratio ==100 ) msg = HIW + "^O^ ";
  else if( ratio >= 90 ) msg = HIG + "^o^ ";
  else if( ratio >= 80 ) msg = GRN + "^_^ ";
  else if( ratio >= 60 ) msg = HIY + "-.- ";
  else if( ratio >= 40 ) msg = YEL + "-_-\"";
  else if( ratio >= 20 ) msg = HIR + "!_! ";
  else                   msg = RED + ">_< ";

  return msg + NOR;
}

string status_string(int status)
{
  string *status_desc=({
    "[1m你覺得身體狀況良好，渾身充滿了活力。",
    "[1;36m你覺得有點頭暈，但還沒什麼大礙。",
    "[1;33m你感到心中陣陣煩躁，眼前朦朧朧的看不真切。",
    "[1;32m你開始覺得噁心，陣陣的暈眩感傳來。",
    "[1;35m你覺得頭痛欲裂，好想找個地方躺下來休息。",
    "[1;31m你覺得天旋地轉，似乎快要暈倒了。"
  });
  if( status >= 1000 ) status=999;
  if( status < 0 )     status=0;
  if( status < 400 )
    return status_desc[0];
  else
    return status_desc[(status-400)/100];
}

varargs int main( object me, string arg, int mode )
{
  object ob;
  int i=0;
  seteuid(getuid(me));

  if( !arg )
    ob = me;
  else if( wizardp(me) ) {
    arg = lower_case(arg);
    ob = present( arg, environment(me) );
    if( !ob )
      ob = find_player(arg);
    if( !ob )
      ob = find_living(arg);
        if( !ob ) {
          ob = FINGER_D->acquire_login_ob(arg);
          i=1;
        }
    if( !ob )
      return notify_fail("你要察看誰的狀態？\n");
  }
  else
    return notify_fail("只有巫師能察看別人的狀態。\n");

  if( mode==1 )
    ob = me->query_temp("pal");

  if( wizardp(me) )
    if( wiz_level(this_player()) < wiz_level(ob) )
      return notify_fail ("沒有這個玩家。\n");
    else wiz_score(ob);
  else
    player_score(ob);
  if(i) destruct(ob);
  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : score
           score <對象名稱>                   (巫師專用)
指令說明 :
           這個指令可以顯示你(妳)或指定對象(含怪物)的基本資料。
           基本資料的設定請參閱 'help setup'。
其他參考 :
           hp
HELP
  );
  return 1;
}
