// Made by leei 
// 有些專為殺手所寫的最佳化 但大都是可以自動判別的
//增設eq為no_get no_steal的參數 by blazakira 2010/12/14
//由於說明檔中影武者的背刺行為是可控制的 但是仍出現失控的情況 調整之 by blazakira 2011/8/16

#include <ansi.h>
#include <combat.h>
inherit NPC;

//三段式
string bar_string =  "●●●●●●●●●●●●●●●●●●●●";
string blank_string= "⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙";
string bmin_string=  "○○○○○○○○○○○○○○○○○○○○";
string status_color(int current, int max);
string gift_color(int k,int i);
string tribar_graph(int val, int eff, int max, string color);
int do_cmd_bak();
void do_cmd_exert();
void do_cmd_cast();
void do_cmd_exert()
{
  command("exert "+query("env/cmd_exert") );
}
void do_cmd_cast()
{ 
  command("cast "+query("env/cmd_cast") );
}

void create()
{
  set_name("武影者",({"sub"}) );
  set("long", "他是一個用忍術變幻出來的分身武影者(sub)。\n");
  set("chat_chance_combat", 90);
  set("chat_msg_combat", ({
    (: do_cmd_bak :),
  }) );
  set("score",1000000);
  setup();
}

void init()
{
  int i;
  object *ppl;
//  if( query_temp() ) //玩家取消背刺功能 所以停止使用相關指令
  ppl = all_inventory(environment(this_object()));
  for( i=0; i < sizeof(ppl); i++ ) {
    //若有兩個人一起有使用武影者時 不會兩個都可命令的情形
    if ( ppl[i]->query_temp("sub")=="USED" ) {
      if( this_object()->query("sub_id")==""+ppl[i]->query("id")+"" && ppl[i]==this_player() ) {
        add_action("see_hp","sc");
        add_action("leave","recall");
        add_action("do_cmd_bak","bak");
        add_action("help_sub","cmds");
      }
    }
  }
}

//使用說明
int help_sub()
{
  write(@HELP
武影者環境設定:   
■設定: %用 SET 指令%
  un_manakee    : 設定不使用 MANAKEE 這個內定的特功。  
  auto_back     : 設定戰鬥完畢後/自動歸位。  
  cmd_bak       : 設定非戰鬥中隱身後自動暗殺行動/需裝備匕首/需取消自動歸位。
  cmd_bellup    : 設定在非戰鬥中使用放出殺氣的指令。

        %以下需設參數%
  cmd_perform   : 設定除manakee(內設)外之武功特功/注意格式為: 基本武功.特功。
  cmd_exert     : 設定內功特功/格式同使用的指令般設定。
  cmd_cast      : 設定施法特功/格式同使用的指令般設定。

■取消: 用 UNSET 指令
  auto_back   : 取消自動歸位設定/改由限制時間歸為設定。
  cmd_bak     : 取消自動暗殺行動。 
   
■武影者指令動作:
   cmds   : 觀看分身指令。
   recall : 喚回分身變回武影者。 
   sc     : 觀看你分身或敵人的精氣神之狀態。
   bak    : 非戰鬥中使用/若設自動暗殺行動，將會暗殺，否則會隱身會起來。
            戰鬥中使用時，若有拿匕首時，將會用背刺來刺敵人。
HELP); 
       return 1;
}
//使用背刺
int do_cmd_bak()
{
  int i;
  object *enemy=this_object()->query_enemy();
  if ( query("env/cmd_bak")!="YES" ) return 1; //沒有啟動自動暗殺就不要用 以符合help之說明
  if ( query("env/auto_back")=="YES" ) return 1; //根據help之說明 啟動自動回歸就不要使用了
  i = sizeof(enemy);
  while(i--) {
    if( enemy[i] && living(enemy[i]) && !enemy[i]->is_corpse()) {
      command("cmd bak "+enemy[i]->query("id"));
    }
  }
  if ( ! is_fighting() ) { command("cmd bak invis"); }
  return 1;
}
//心跳設定
void heart_beat()
{
  int i, j, k, l, z;
  object *ppl, *enemy, *kill, *inv, body;
  string sk , act, perform;

  // 消耗分身以內力算之值後 喚回 
  if( environment() && !is_fighting() ) {
    if ( !query("back_time") ) {
      set("back_time",query("force")/5 );
    }
    // 自動喚回設定
    if ( query("back_time") > 10 && query("env/auto_back")!="YES" ) {
      add("back_time",-1);
    }
    else {
      call_out("leave", 1);
    }
    //背刺環境設定
    if ( query("env/cmd_bak")=="YES" && query_temp("invis") ) {
      inv = all_inventory(environment());
      for(l=0;l<sizeof(inv);l++) {                   
        if ( query("sub_id")!=""+inv[l]->query("id")+"" ) {
          if( inv[l]->is_character() || userp(inv[l]) )
            command("cmd bak "+inv[l]->query("id"));
          }
        }
      }
    }
    //放出殺氣
    if ( query("env/cmd_bellup")=="YES" && !query_temp("bell") ) {
      command("cmd bellup");
      set_temp("bell",1);
    }
    //另設特功
    if (  !query_temp("CMD_PEC") ) {
      if ( query("env/un_manakee")!="YES" ) {
        add("chat_msg_combat",({ (: command,"perform throwing.manakee":), //在這逗點之後仍可增加相關指令
        }) ); //為add("chat_msg_combat")的結束
      }
      if ( perform=query("env/cmd_perform") ) {
        add("chat_msg_combat",({ (: perform_action, perform :), }) ); } //目前沒有其他功能 所以合併成一行
      if ( query("env/cmd_exert") ) {
        add("chat_msg_combat",({ (: do_cmd_exert :), }) ); } //同上
      if ( query("env/cmd_cast") ) {
        add("chat_msg_combat",({ (: do_cmd_cast  :), }) ); } //同上
      set_temp("CMD_PEC",1);
    }
    // 若有一方在戰鬥,另一方會加入戰鬥
    if(environment(this_object())){
    ppl = all_inventory(environment(this_object()));
    for( i=0; i < sizeof(ppl); i++ ) {
      if ( ppl[i]->query_temp("sub")=="USED" ) {
        if ( this_object()->query("sub_id")==""+ppl[i]->query("id")+"" ) {
          if ( ppl[i]->is_fighting() ) {
            enemy = ppl[i]->query_enemy();
          }
          else {
            enemy = query_enemy();
          }
          j = sizeof(enemy);
          while(j--) {
            if( enemy[j] && living(enemy[j]) ) {
              if ( ppl[i]->is_fighting() && !is_fighting() ) {
                kill_ob(enemy[j]);
                if( userp(enemy[j]) ) enemy[j]->fight_ob(this_object());
                else enemy[j]->kill_ob(this_object());
                message("vision",
                  MAG + ""+name() + "的分身 " + HIC + ""+this_object()->query("old_name")+
                  "" + NOR + "" + MAG + " 看到"+name()+"有危險，馬上跑來救援了。\n" + NOR ,
                  environment(),this_object() );
              }
              if (is_fighting() && !ppl[i]->is_fighting() ) {
                ppl[i]->kill_ob(enemy[j]);
                if( userp(enemy[j]) ) enemy[j]->fight_ob(ppl[i]);
                else enemy[j]->kill_ob(ppl[i]);
                message("vision",
                  MAG + ""+name() + " 看到分身有危險，馬上加入戰鬥了。\n" + NOR ,        
                  environment(),this_object() );
              }
            }
          }
        }
      }
    }
  }
  ::heart_beat();
}
//離開設定
int leave()
{
  int i, exp;
  object *ppl, fighter;
  exp = query("combat_exp") - query("old_exp");
  ppl = all_inventory(environment(this_object()));
  for( i=0; i < sizeof(ppl); i++ ) {
    if ( ppl[i]->query_temp("sub")=="USED" ) {
      if ( this_object()->query("sub_id")==""+ppl[i]->query("id")+"" ) {
        //戰鬥中喚回
        if ( is_fighting() ) {
          if ( ppl[i]->query("force") < 50 ) {
            return notify_fail("你的內力不夠，無法喚回分身\n");
          }
          ppl[i]->add("force",-50);
          message("vision",HIY + ""+name() +
            "看情況不妙，急忙地叫回分身。\n" + NOR ,environment(),this_object() );
        }
        fighter=new("/autoload/killer/pet2.c");
        fighter->set("name",""+this_object()->query("old_name")+"");
        fighter->move(ppl[i]);
        //增加備份經驗
        if ( exp > 0 ) { ppl[i]->add("sub_exp",exp); }
      }
      ppl[i]->delete_temp("sub");
    }
  }
  message("vision",
    MAG + ""+name() + "的分身 " + HIC + ""+this_object()->query("old_name")+
    "" + NOR + "" + MAG + " 歸體了。\n" + NOR , environment(),this_object() );
  destruct(this_object());
  return 1;
}

//呼叫出 此可適用各門派 該有的都有了 
void invocation(object me)
{
  string skill, m_skill, str, *gift, *sk, *en;
  int i, k, e, lv_1, lv_2;
  object *enemy, *eq, weapon, secondary, type, amount;
  mapping my=(mapping)me->query_entire_dbase();
  mapping skills = me->query_skills();
  mapping map =me->query_skill_map();

  //殺敵
  enemy = me->query_enemy();
  i = sizeof(enemy);
  while(i--) {
    if( enemy[i] && living(enemy[i]) ) {
      kill_ob(enemy[i]);
      if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
      else enemy[i]->kill_ob(this_object());
    }
  }

  //設定天賦
  gift= ({"long","con","str","int","spi","per","kar","cps","cor",
          "kee","eff_kee","max_kee","gin","eff_gin","max_gin","sen",
          "eff_sen","max_sen","force","max_force","atman","max_atman",
          "mana","max_mana","age","combat_exp","MKS","PKS","force_factor",
          "mana_factor","atman_factor","sub_exp","spells",
          "nickname","title","water","food","birthday","status","race",
          "bellicosity","potential","learned_points","gender","class",
          "describe","apply","functions","family","quest","quests","env"});

  for(i=0 ; i < sizeof(gift) ; i++) {
    set(""+gift[i]+"",my[gift[i]]);
  }
  set("old_exp",my["combat_exp"] );
  set_name(my["name"],({"sub "+my["id"],my["id"],"sub"}));

  //設定技能
  sk = sort_array( keys(skills), (: strcmp :) ); ;
  for(i=0;i<sizeof(sk);i++) {
    set_skill(sk[i], skills[sk[i]] );

    //裝備技能
    en = ({"force","staff","throwing","array","blade","cure","dagger",
           "lance","magic","dodge","move","parry","poison","spells",
           "stabber","stick","sword","unarmed","whip"});

    for(k=0;k<sizeof(en);k++) {
      if ( SKILL_D(sk[i])->valid_enable(en[k]) && sk[i]==map[en[k]] ){
        map_skill(en[k],sk[i]);
      }
    }
  }

  weapon = me->query_temp("weapon");
  secondary=me->query_temp("secondary_weapon");

  //裝備防具及雙手武器和主武器數量設定
  eq = all_inventory(me);
  for(e=0; e<sizeof(eq); e++) {
    if( eq[e]->query("equipped") ) {
      str=(string)base_name(eq[e]);

      if( weapon && weapon==eq[e] ) {
        amount=carry_object(""+str+"");
        if( (int)weapon->query_amount() > 1 ) {
          amount->set_amount( (int)weapon->query_amount() );
        }
        amount->wield();
      }
      else { 
        type=carry_object(""+str+"");
        type->move(this_object());
        if(!environment(type)) continue;
        type->wear();
        type->wield();
      }
    }
  }
  all_inventory(this_object())->set("no_get",1); //防撿
  all_inventory(this_object())->set("no_steal",1); //防偷
  set_leader(me);
}

//死亡設定
void die()
{
  int i, e;
  object *eq;
  object *ppl;

  eq = all_inventory(this_object());
  for(e=0; e<sizeof(eq); e++) {
    destruct(eq[e]);
  }

  ppl = all_inventory(environment(this_object()));
  for( i=0; i<sizeof(ppl); i++ ) {
    if ( ppl[i]->query_temp("sub","USED") ){
      if ( this_object()->query("sub_id")==""+ppl[i]->query("id")+"" ) {
        ppl[i]->set("monkey_lv",70);
      }
      ppl[i]->delete_temp("sub");
    }
  }
  ::die();
}

//狀態說明
int see_hp(string arg)
{
  int i;
  string str="",sta="",stb="";
  object *inv, wa, wb, ob;
  mapping my;
  
  if(!arg || arg == "") { ob=this_object(); }
  else { ob = present(arg, environment(this_object())); }
  my=(mapping)ob->query_entire_dbase(); 
  if ( !ob || !ob->is_character() || ob->is_corpse() ) { return 1; }

  printf("%s" + NOR + "之狀態:\n",(my["back_time"]>0) ?
    "你的分身『" + HIC + ""+my["old_name"]+"』" : "敵人『" + HIC + ""+my["name"]+"』" );
  printf("%s  %s\n\n□ 年齡：%s歲\t\t性別：%s %s\n□ 看來 %s 練武的好對象\n\n",
    RANK_D->query_rank(ob),
    ob->short(),chinese_number(my["age"]),my["gender"],
    (my["back_time"]>0) ? 
    "\n□ 將於" + HIR + ""+chinese_number(my["back_time"])+"" + NOR + "系統時間後歸位"+
    "\n□ 你現在擁有 "+chinese_number(my["sub_exp"])+" 點經驗\t可望得 "+
    chinese_number(my["combat_exp"]-my["old_exp"])+" 點備份經驗"
    : "" ,(my["combat_exp"] < this_object()->query("combat_exp")*3 &&
    my["combat_exp"] > this_object()->query("combat_exp")*8/10 ) ? "是" :
    "不是",);

  write("■精："+tribar_graph(my["gin"],my["eff_gin"],my["max_gin"],MAG)+"");
  printf("\t%s%3d/%d %s(%d%%) " + NOR + "靈：%s%3d/%d \n" + NOR,
    status_color(my["gin"], my["eff_gin"]), my["gin"], my["eff_gin"],
    status_color(my["eff_gin"], my["max_gin"]), my["eff_gin"]*100/my["max_gin"],
    status_color(my["atman"], my["max_atman"]), my["atman"], my["max_atman"],);

  write("■氣："+tribar_graph(my["kee"],my["eff_kee"],my["max_kee"],CYN)+"");
  printf("\t%s%3d/%d %s(%d%%) " + NOR + "內：%s%3d/%d \n" + NOR,
    status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
    status_color(my["eff_kee"], my["max_kee"]), my["eff_kee"]*100/my["max_kee"],
    status_color(my["force"], my["max_force"]), my["force"], my["max_force"],);

  write("■神："+tribar_graph(my["sen"],my["eff_sen"],my["max_sen"],YEL)+"");
  printf("\t%s%3d/%d %s(%d%%) " + NOR + "法：%s%3d/%d \n" + NOR,
    status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
    status_color(my["eff_sen"], my["max_sen"]), my["eff_sen"]*100/my["max_sen"],
    status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],);

  inv = all_inventory(ob);
  for(i=0; i<sizeof(inv); i++) {
    if(inv[i]->query("equipped") ) {  
      str+= (inv[i]->query("armor_type")=="head"      ? "[頭具]": "");
      str+= (inv[i]->query("armor_type")=="cloth"     ? "[衣服]": "");
      str+= (inv[i]->query("armor_type")=="armor"     ? "[甲冑]": "");
      str+= (inv[i]->query("armor_type")=="neck"      ? "[項鍊]": "");
      str+= (inv[i]->query("armor_type")=="shield"    ? "[盾牌]": "");
      str+= (inv[i]->query("armor_type")=="waist"     ? "[腰帶]": "");
      str+= (inv[i]->query("armor_type")=="hands"     ? "[手套]": "");
      str+= (inv[i]->query("armor_type")=="boots"     ? "[鞋子]": "");
      str+= (inv[i]->query("armor_type")=="cape"      ? "[披風]": "");
      str+= (inv[i]->query("armor_type")=="armbands"  ? "[臂環]": "");
      str+= (inv[i]->query("armor_type")=="leggings"  ? "[綁腿]": "");

      wa=ob->query_temp("weapon");
      wb=ob->query_temp("secondary_weapon");
      sta+= (inv[i]==wa ? "["+inv[i]->query("name")+"]" : "");
      stb+= ((inv[i]==wb || inv[i]->query("armor_type")=="shield") ?
        "["+inv[i]->query("name")+"]" : "");
    }
  }
  printf("\n□ 右手：%s\t\t左手：%s\n", sta, stb,);
  printf("□ 防護：" + HIY + "%s\n" + NOR, str,);
  return 1;
}

string status_color(int current, int max)
{
  int percent;
  if( max ) percent = current * 100 / max;
  else percent = 100;

  if( percent > 100 ) return HIC;
  if( percent >= 90 ) return HIG;
  if( percent >= 70 ) return HIY;
  if( percent >= 50 ) return HIM;
  if( percent >= 30 ) return HIB;
  if( percent >= 10 ) return HIR;
  return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
  return color + bar_string[0..(val*20/max)*2-1]
    + ((eff > val) ? blank_string[(val*20/max)*2..(eff*20/max)*2-1]: "")
    + ((max > eff) ? (bmin_string[(eff*20/max)*2..(max*20/max)*2-1]): "")
    + NOR;
}

string gift_color(int k,int i)
{
  int value=k - i ;
  if ( value >= 11 ) return BLU;
  if ( value >= 6 )  return CYN;
  if ( value >= 1  ) return YEL;
  if ( value == 0  ) return GRN;
  if ( value <= -1 ) return RED;
  return NOR;
}
