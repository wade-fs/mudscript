// damage.c 修正 by babe
// 增加一項在特定的房間pk不會死....by chan design
//add by bss,有些temp不想被delete,可以加在NO_DEL_TEMP裡面(只能做最上層)

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
#include <pkla.h>
#define NO_DEL_TEMP ({"marks","channels","last_damage_from","ride_name"})
#define DAMAGE_EX __DIR__"damage_ex.c"

int i, gin, kee, sen, force, mana, atman,exp_rate=0,clan_war=0,clan_wark,other=1,all_exp=0,my_exp;
int get_exp, get_pot,war_exp,war_pot,war_level, pal_exp, pal_pot, exp, base, eita;
object x,y;
int ghost = 0;
int is_ghost() { return ghost; }
int cal_damage(object me,int damage);
void eval( string what, object ob );

varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( type!="gin" && type!="kee" && type!="sen" )
    error("F_DAMAGE: 傷害種類錯誤( 只能是 gin, kee, sen 其中之一 )。\n");
  if( objectp(who) ) set_temp("last_damage_from", who);
  else{
    if(this_player())
      if(living(this_player()))
        set_temp("last_damage_from",this_player());
  }
  if(query(type)<0){
    if(!query_temp("last_damage_from")) //如果到死都找不到是誰下的手
      set_temp("last_damage_from",this_object()); //就當作是自殺的吧 by bss
    return 1;
  }
  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
if((query_temp("mana_shield")||query_temp("mana_shield2")||query_temp("mana_shield3"))&&type=="kee")
  {
     if( query("atman")>50)
     {
         type = "atman";
     }/*else{
         delete_temp("mana_shield");
                 delete_temp("mana_shield2");
     }*/
  }
  if(query_temp("no_armor_effect"))
    this_object()->delete_temp("no_armor_effect");
  else
    damage=cal_damage(this_object(),damage);
  val = (int)query(type) - damage;
   if( val >= 0 ) { set(type, val); }
   else if( type == "atman") { set(type,0); delete_temp("mana_shield"); delete_temp("mana_shield2");}
   else set(type,-1);
  if(query(type) <0 && !query_temp("last_damage_from"))
    set_temp("last_damage_from",this_object());
  set_heart_beat(1);
  return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
  int val;
  if( type!="gin" && type!="kee" && type!="sen" )
    error("F_DAMAGE: 傷害種類錯誤( 只能是 gin, kee, sen 其中之一 )。\n");
  if( objectp(who) ) set_temp("last_damage_from", who);
  else{
    if(this_player())
      if(living(this_player()))
        set_temp("last_damage_from",this_player());
  }
  if(query(type)<0){
    if(!query_temp("last_damage_from")) //如果到死都找不到是誰下的手
      set_temp("last_damage_from",this_object()); //就當作是自殺的吧 by bss
    return 1;
  }
  if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
  if(query_temp("no_armor_effect"))
    this_object()->delete_temp("no_armor_effect");
  else
    damage=cal_damage(this_object(),damage);
  val = (int)query("eff_" + type) - damage;
  if( val >= 0 ) set("eff_" + type, val);
  else {
    set( "eff_" + type, -1 );
    val = -1;
  }
  if( (int)query(type) > val ) set(type, val);
  if(query(type) <0 && !query_temp("last_damage_from"))
    set_temp("last_damage_from",this_object());
  set_heart_beat(1);
  return damage;
}

int receive_heal(string type, int heal)
{
  int val;
  if( heal < 0 ) error("F_DAMAGE: 恢復值為負值。\n");
  if( type!="gin" && type!="kee" && type!="sen" )
    error("F_DAMAGE: 恢復種類錯誤( 只能是 gin, kee, sen 其中之一 )。\n");
  val = (int)query(type) + heal;
  if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
  else set( type, val );
  return heal;
}

int receive_curing(string type, int heal)
{
  int max, val;
  if( heal < 0 ) error("F_DAMAGE: 恢復值為負值。\n");
  if( type!="gin" && type!="kee" && type!="sen" )
    error("F_DAMAGE: 恢復種類錯誤( 只能是 gin, kee, sen 其中之一 )。\n");
  val = (int)query("eff_" + type);
  max = (int)query("max_" + type);
  if( val + heal > max ) {
    set("eff_" + type, max);
    return max - val;
  } else {
    set( "eff_" + type, val + heal);
    return heal;
  }
}

void unconcious()
{
  object defeater, officer;
  if( !living(this_object()) ) return;
  if( wizardp(this_object()) && query("env/immortal") ) return;
  if( this_object()->query_temp("pk_fight") ) {
      if( !(officer = find_living("pkla officer")) )
          return;
      officer->pk_lose(this_object());
      return;
  }
  if( objectp(defeater = query_temp("last_damage_from")) )
    COMBAT_D->winner_reward(defeater, this_object());
  this_object()->remove_all_enemy();
  message("system", HIR + "\n你的眼前一黑﹐接著什麼也不知道了....\n\n" + NOR,
    this_object());
  this_object()->disable_player(" <昏迷不醒>");
  set("gin", 0);
  set("kee", 0);
  set("sen", 0);
  set_temp("block_msg/all", 1);
  set_temp("unconcious", 1);
  COMBAT_D->announce(this_object(), "unconcious");
  call_out("revive", random(100 - 2*query_con()) + 30);
}
//給被doctor起死回生的人用的 by bss
void relive()
{
  message("system", HIR + "\n你的眼前一黑﹐接著什麼也不知道了....\n\n" + NOR,
    this_object());
  this_object()->disable_player(" <昏迷不醒>");
  set("gin", 0);
  set("kee", 0);
  set("sen", 0);
  set_temp("block_msg/all", 1);
  set_temp("unconcious", 1);
  COMBAT_D->announce(this_object(), "unconcious");
  call_out("revive", random(100 - 2*query_con()) + 30);
}
varargs void revive(int quiet)
{
  remove_call_out("revive");
  set_temp("unconcious", 0);
  while( environment()->is_character() )
    this_object()->move(environment(environment()));
  this_object()->enable_player();
  if( !quiet ) {
    COMBAT_D->announce(this_object(), "revive");
    set_temp("block_msg/all", 0);
    message("system", HIY + "\n慢慢地你終於又有了知覺....\n\n" + NOR,
      this_object());
  } else
    set_temp("block_msg/all", 0);
}
//fix by bss
//pal的計算先消了
void die()
{
        object  *living_here, ob, officer, *t, corpse, killer, me=this_object(), where, pal;
        mapping my;
        string  *killer_name, *my_key,head,clan_d,clan_k,death_str, money,stdby_str,go_room;

        if(!me) return ;
        if( !living(me) ) revive(1);
        if( environment() && environment()->query("undead") ) return;
        if( wizardp(me) && query("env/immortal") ) return;
//這部份應該是試鍊塔的部份
//我想先留著好了 by bss
        where = environment(me);
/*
        if( where->query("no_die_room") ) {
          if( userp(me)&&(!me->query("ckill")) ) {
            me->remove_all_killer();
            all_inventory(environment())->remove_killer(me);
            me->dismiss_team();
            eval( "gin", me );
            eval( "kee", me );
            eval( "sen", me );
            me->add("quest/lose_game",1);
            me->move("/open/steeple/ticket");
            return;
          }
        }
*/
//做個總的不會死的房間by bss
//本來no_die_room已經被試鍊塔用了，所以先關掉試鍊塔的部份
        if(where->query("no_die_room")){
          if(userp(me) && !me->query("ckill")){
            me->remove_all_killer();
            all_inventory(where)->remove_killer(me);
            me->dismiss_team();
            me->set("eff_gin",me->query("max_gin"));
            me->set("eff_kee",me->query("max_kee"));
            me->set("eff_sen",me->query("max_sen"));
            me->set("gin",me->query("max_gin"));
            me->set("kee",me->query("max_kee"));
            me->set("sen",me->query("max_sen"));
            if(me->query_temp("unconcious"))
              me->revive();
            go_room=where->query("die_room");
            if(!go_room){
              me->move("/open/common/room/inn");
              return;
            }
            if(go_room[sizeof(go_room)-2..sizeof(go_room)-1]!=".c")
              go_room+=".c";
            if(file_size(go_room) < 0){
              me->move("/open/common/room/inn");
              return ;
            }
            me->move(go_room);
            return ;
          }
        }
        // 將 clan_war, pkla, mpk 重整 by ACKY
        if( where->query( "pkroom", 1 ) ) {
                if( userp(me) ) {
                        if( !userp(killer=me->query_temp("last_damage_from")) )
                                killer = me->query_emeny()[0];
                        if(killer)
                        CHANNEL_D->do_channel( killer, "dead",
                                sprintf( "哈! 哈! 蠢蛋%s死在我手裡了!", me->name(1) ) );
                        me->remove_all_killer();
                        all_inventory(environment())->remove_killer(me);
                        me->dismiss_team();
                        me->clear_condition();
                        if( !wizardp(me) ) {
                                if(killer)
                                killer->add( "pkgame", 1 );
                                living_here = all_inventory( me );
                                for( i=0; i<sizeof(living_here); i++ ) {
                                        money = living_here[i]->query("id");
                                        if( money=="thousand-cash" || money=="gold" || money=="silver" || money=="coin" )
                                                living_here[i]->move(environment(me));
                                }
                        }
                        eval( "gin", me );
                        eval( "kee", me );
                        eval( "sen", me );
                        me->move( "/open/capital/room/r66" );
                        tell_room( where, me->query("name")+"被人抬了出去。\n", me );
                        message_vision( HIR + "$N被人從武鬥會場抬出來, 渾身是血, 狼狽不堪。\n" + NOR, me );
                        "/open/mulitpk/room/room01.c"->valid_leave(me,"out");
                        return;
                }
        }
        // 清除藥性
        me->set("status",0);
        me->clear_condition();

        // 在 clan_war 中死掉的
        if( me->query_temp("war/type") ) {
                if( me->query_temp("war/type")=="multipk" ) {
                        if( !(officer = find_living("clan_war officer")) )
                                return;
                        officer->multipk_lose(me);
                        return;
                }
        }

        // 在 pkla 中死掉的
        if( me->query_temp("pk_fight") ) {
                if( !(officer = find_living("pkla officer")) )
                        return;
                officer->pk_lose(me);
                return;
        }

//這是小渡在1998.8.24加入的有關殺手的追殺對象
//chan重新修正by 1998.9.17
//wataru 1998.10.25 再次修正
//                  避免有替身的玩家不會死掉，且title仍在
//                  所以把檢查title的改到替身之前，且把死亡的部分加上去
//              問題是接下來這一兩行，因為不能放在檢查title的block裡面
//      因為他是檢查殺人者，並且設定物件的內容
//      o樣會形成，有set_temp殺人者
//      不知道對於有替身者有何影響？因為，原本有替身者，並不會被偵察這一項
 if( objectp(killer = query_temp("last_damage_from")) || killer = me)
       set_temp("my_killer", killer->query("id"));
 if (me->query("title") == HIR + "殺手全力追殺的人頭" + NOR)
 {
       COMBAT_D->announce(me, "dead");
       COMBAT_D->killer_reward(killer, me);
       if( objectp(corpse = CHAR_D->make_corpse(me, killer)) )
        if(userp(me))
          corpse->set("time",2);
        else
          corpse->set("time",1);
        corpse->move(environment());
        new("/open/killer/obj/kill_yar_head.c")->move(corpse);
        me->delete("title");
        me->remove_all_killer();
        all_inventory(environment())->remove_killer(me);
        me->dismiss_team();
        if( userp(me) )
        {
            ob = me->query_temp("link_ob");
            my = me->query_entire_temp_dbase();
            my_key = keys(my);
            foreach(x in my_key)
            {  me->delete_temp(x); }
            me->set_temp("link_ob", ob);
            me->setup();
            set("gin", 1);  set("eff_gin", 1);
            set("kee", 1);  set("eff_kee", 1);
            set("sen", 1);  set("eff_sen", 1);
            ghost = 1;
            me->set("ghost",1);
            me->move(DEATHROOM);
            DEATHROOM->start_death(me);
            me->save();
       }
       else
          destruct(me);
       return ;
  }
  if((sizeof(me->query("clan")) > 1 ) && (CLAN_D->clan_query(me->query("clan/id"),"war")))
   clan_war =1;
  if( (me->query("standby") > 0) && !clan_war) {
//記錄替身死亡時間by bss
        me->set("standby_dead_time",time());
            me->add("standby", -1);
            me->clear_condition();
            me->remove_all_enemy();
            gin = me->query("max_gin");
            kee = me->query("max_kee");
            sen = me->query("max_sen");
            force = me->query("max_force");
            mana = me->query("max_mana");
            atman = me->query("max_atman");
            me->set("eff_gin", gin);
            me->set("gin", gin);
            me->set("eff_kee", kee);
            me->set("kee", kee);
            me->set("eff_sen", sen);
            me->set("sen", sen);
            me->set("force", force);
            me->set("mana", mana);
            me->set("atman", atman);
            me->set("water", 0);
            me->set("food", 0);
            me->delete("ckill"); //取消ckill所設的....by chan
            me->delete("ckill_id"); //取消ckill所設的....by chan
            me->move(me->query("startroom"));
            tell_object(me, "你用掉一個替身了, 你的替身正在地府觀光呢。\n");
            log_file("death_stdby",sprintf("%s用掉一個替身被%s(%s)所殺於%s\n",
            me->query("id"),killer->query("name"),killer->query("id"),ctime(time())));
            return;
        }
  // 清除藥性
  me->set("status",0);
  // Clear all the conditions by death.
  me->set("force",10);
  me->clear_condition();
  me->clear_condition("burn");
  me->clear_condition("cold");
  me->clear_condition("hart");
  me->clear_condition("god_out");
  me->clear_condition("u-stial");
  me->clear_condition("blade");
  me->clear_condition("star-stial");
  //清掉..burn hart cold及god_out防止死了又死 by Chan 7/7
  //清除來不及解除的魔域波幻迷掌...被折磨致死大概很難過吧
  //By Roger
  if(me->query_condition("mogi"))
  me->clear_condition("mogi");
//只有這種方法能解除波幻迷掌
  COMBAT_D->announce(me, "dead");
        if( objectp(killer = query_temp("last_damage_from")) || killer = me)
                set_temp("my_killer", killer->query("id"));
//幫派戰爭的部份..........
   if(userp(killer))
    clan_k=killer->query("clan/id");
   if(userp(me))
     clan_d=me->query("clan/id");
   if(clan_d && clan_k)
    {
      if(find_player("bss"))
      tell_object(find_player("bss"),sprintf("first steps\n"));
    clan_war=CLAN_D->clan_query(clan_d,"war");
    clan_wark=CLAN_D->clan_query(clan_k,"war");
    if(clan_war && clan_wark)
      if(find_player("bss"))
      tell_object(find_player("bss"),sprintf("second steps\n"));
      if(CLAN_D->clan_query(clan_d,"clan_war") == clan_k) {
      if(find_player("bss"))
      tell_object(find_player("bss"),sprintf("%s在戰場上被%s殺死了。", me->name(1), killer->name(1)));
      //戰功的部份重新處理...by chan
      //mob及npc要lv 16以上才有戰功..
      //player的戰功是四點.....
      //在整理..取消mob的戰功.改成殺死玩家時有十點戰功......
if(userp(me)&&(me->query("combat_exp")>1000000)&&
  ((me->query("potential")-me->query("learned_points"))>=10000))
         killer->add("war_kills",10);
//       else if(me->query("combat_exp") > 2400000)
//         killer->add("war_kills",1);
         killer->add("PKS", 1);
         CLAN_D->add_clanset(clan_k,"war_kill",1);
         me->clear_condition();
         me->set_temp("snow-powerup",0);
         me->set("bellicosity", 0);
         war_exp = 100000;
         me->add("combat_exp", -war_exp);
         war_pot = 10000;
         me->add("potential",-war_pot);
         CHANNEL_D->do_channel(this_object(), "war",
         sprintf("%s在戰場上被%s殺死了。", me->name(1), killer->name(1)));
log_file("clan/killwar",sprintf("%s在戰場上被%s殺死了\n",
me->short(1),killer->short(1)));
        if(me->query("clan/rank") == 1)
           CLANV_D->clan_stop_kill(clan_d);
       other=0;
      }
    }
//以上都是幫派戰爭的部份..
if(other)
  COMBAT_D->killer_reward(killer, me);
  death_str="";
  death_str=me->query("name")+"被"+killer->query("name")+"所殺在"+ctime(time())+"\n";
       write_file("/open/death/death_record",death_str);
  if( objectp(corpse = CHAR_D->make_corpse(me, killer)) )
   if(userp(me))
    corpse->set("time",5);
   else
    corpse->set("time",1);
    corpse->move(environment());
  killer_name=me->query_killer();
  living_here=all_inventory(environment());

  if(member_array(killer,living_here) == -1)
        living_here += ({killer});

  foreach(x in living_here)
    foreach(y in killer_name)
      if(y==x->query("id")) { //exp運算...by chan
        my_exp=x->query("combat_exp");
        if(my_exp < 1000)
          my_exp=1000;
        my_exp=my_exp/1000;
        all_exp=all_exp+my_exp;
       }
  foreach(x in living_here)
    foreach(y in killer_name)
      if(y==x->query("id")) {

// 計算所得 exp, pot by ACKY
        switch( exp = me->query("combat_exp") )
        {
        case 0..3000:
                base=0;
                eita=632;
                exp =0;
                break;
        case 3001..7000:
                base=9;
                eita=632;
                exp-=3000;
                break;
        case 7001..15000:
                base=21;
                eita=649;
                exp-=7000;
                break;
        case 15001..31000:
                base=42;
                eita=787;
                exp-=15000;
                break;
        case 31001..63000:
                base=72;
                eita=1055;
                exp-=31000;
                break;
        case 63001..127000:
                base=114;
                eita=1512;
                exp-=63000;
                break;
        case 127001..255000:
                base=171;
                eita=2272;
                exp-=127000;
                break;
        case 255001..511000:
                base=243;
                eita=3539;
                exp-=255000;
                break;
        case 511001..1023000:
                base=333;
                eita=5668;
                exp-=511000;
                break;
        case 1023001..2047000:
                base=444;
                eita=9281;
                exp-=1023000;
                break;
        case 2047001..4095000:
                base=576;
                eita=15476;
                exp-=2047000;
                break;
        case 4095001..8191000:
                base=732;
                eita=26200;
                exp-=4095000;
                break;
        case 8191001..16383000:
                base=915;
                eita=44929;
                exp-=8191000;
                break;

        case 16383001..32767000:
                base=1125;
                eita=77895;
                exp-=16383000;
                break;

        default:
                get_exp=1400;
                get_pot=175;
                break;
        }

        if( me->query("combat_exp") < 32767000 ) {
                get_exp = base + exp/eita;
                get_pot = get_exp / 8;
                if( get_exp < 10 ) get_exp = 10;
                if( get_pot < 5  ) get_pot =  5;
        }
        if(me->query("no_exp")) {
         get_exp = 0;
         get_pot = 0;
        } //身上有設no_exp的沒有exp可以拿..
          where = environment(x);  //mpk room沒有exp
          if(where->query("pkroom",1)) {
          get_pot=0 ;
          get_exp=0;
          }
          if(me->query("combat_exp")<x->query("combat_exp")*8/10) {
          get_pot=0;
          get_exp=0; }
          if(me->query("combat_exp")>x->query("combat_exp")*3) {
          get_pot=0;
          get_exp=0; }
//組team得exp的部份需要好好研究一下
/*
          if( !pointerp(t = x->query_team()) ) //team的部份
           team_number=1;
          else
           team_number=sizeof(t);
*/
/*        if(team_number < 2) {
          get_exp=get_exp/team_number;
          get_pot=get_pot/team_number;
          }else {
*/
          my_exp=x->query("combat_exp");
          if(my_exp < 1000)
          {
          get_exp=10;
          get_pot=5;
          }
          else
          {
          my_exp=my_exp/1000;
          get_exp=(get_exp*my_exp)/all_exp;
          get_pot=(get_pot*my_exp)/all_exp;
          }
          x->add("potential",(int)get_pot);
          x->add("combat_exp",(int)get_exp);
          tell_object(x,"你得到 "+sprintf("%O",(int)get_exp)+" 點實戰經驗。\n");
          tell_object(x,"你得到 "+sprintf("%O",(int)get_pot)+" 點潛能。\n");
//從這裏開始設定!!!!
if( userp(x) )
        if( x->query("combat_exp")>3000000 && !x->query("hero/limit") ) {
                tell_object( x, HIC+"你忽然間感覺到自己的武學修養在歷經多次生死戰鬥後, 達到隨心所欲的境界!\n" + NOR );
                tell_object( users(), HIR+x->query("name")+"在歷經無數次生死戰鬥後, 終於成為一代大俠!\n" + NOR );
                tell_object( x, "你可以使用 design_skill, show_skill 的指令, 來設計自己的招式, 請打 help 一代大俠。\n" );
                x->set( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>4000000 && x->query("hero/limit")<2 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到出神入化的境界!\n" + NOR );
                x->add( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>5000000 && x->query("hero/limit")<3 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到驚世駭俗的境界!\n" + NOR );
                x->add( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>6000000 && x->query("hero/limit")<4 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到武道大成的境界!\n" + NOR );
                x->add( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>7000000 && x->query("hero/limit")<5 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到成宗立派的境界!\n" + NOR );
                x->add( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>8000000 && x->query("hero/limit")<6 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到登峰造極的境界!\n" + NOR );
                x->add( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>9000000 && x->query("hero/limit")<7 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到舉世無雙的境界!\n" + NOR );
                x->add( "hero/limit", 1 );
        }
        else if( x->query("combat_exp")>10000000 && x->query("hero/limit")<8 ) {
                tell_object( x, HIY + "你感覺到自己的武學修為更上層樓, 達到學究天人的境界!\n" + NOR );
                tell_object( users(), HIM+x->query("name")+"在歷經重重的艱苦修為後, 終於突破自己的武學極限, 成為學究天人!\n" + NOR );
                tell_object( x, "你可以使用 ut 至尊頻道。\n" );
                x->add( "hero/limit", 1 );
        }
}

        me->remove_all_killer();
        all_inventory(environment())->remove_killer(me);
        me->dismiss_team();
        if( userp(me) ) {
        ob = me->query_temp("link_ob");
        my = me->query_entire_temp_dbase();
        my_key = keys(my);
//add by bss,有些temp不想被delete,可以加在上面那個NO_DEL_TEMP裡面(只能做最上層)
        for(i=0;i<sizeof(my_key);i++){
          if(member_array(my_key[i],NO_DEL_TEMP)==-1)
            me->delete_temp(my_key[i]);
        }
        me->set_temp("link_ob", ob);
        me->setup();
        set("gin", 1);  set("eff_gin", 1);
        set("kee", 1);  set("eff_kee", 1);
        set("sen", 1);  set("eff_sen", 1);
        ghost = 1;
        me->set("ghost",1);
        me->move(DEATHROOM);
        DEATHROOM->start_death(me);
        me->save();
        }
        else {
                if( me->query("master") ) {
                        me->set( "gin", 1 );    me->set( "eff_gin", 1 );
                        me->set( "kee", 1 );    me->set( "eff_kee", 1 );
                        me->set( "sen", 1 );    me->set( "eff_sen", 1 );
                        me->set( "bellicosity", 0 );
                        me->set( "combat_exp", me->query("combat_exp")/20*19 );
                        DAMAGE_EX->cal_parta(x,me);
                        me->save();
                        if( ob=find_player(me->query("master")) )
                                ob->delete_temp("pal");
                }
                destruct(me);
        }
}

void eval( string what, object ob )
{
        int max;

        max = ob->query( "max_"+what )/10;
        if( ob->query( what ) < max )
                ob->set( what, max );
        if( ob->query( "eff_"+what ) < max )
                ob->set( "eff_"+what, max );
}

void reincarnate()
{
  ghost = 0;
  this_object()->set("ghost",0);
  set("eff_gin", query("max_gin"));
  set("eff_kee", query("max_kee"));
  set("eff_sen", query("max_sen"));

}
int max_food_capacity() { return query_weight() / 200; }
int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
  int update_flag;
  mapping my;

//  if( this_object()->is_fighting() ) return -1;

  update_flag = 0;

  my = query_entire_dbase();
  if(!this_object()) return 1;//竟然會有抓不到this_object(),看到鬼 by bss

  if(!wizardp(this_object())){
    if( my["water"] > 0 ) my["water"] -= 1;
    else if( userp(this_object()) ) return update_flag;

    if( my["food"] > 0 ) my["food"] -= 1;
    else if( userp(this_object()) ) return update_flag;
  }

  my["gin"] += my["con"] + my["atman"] / 8;
  if( my["gin"] >= my["eff_gin"] ) {
    my["gin"] = my["eff_gin"];
    if( my["eff_gin"] < my["max_gin"] ) { my["eff_gin"] ++; update_flag++; }
  } else update_flag++;

  if(my["force"] >1)
  my["kee"] += my["con"] + my["force"] / 40 ;
  else
  my["kee"] += my["con"];
  if( my["kee"] >= my["eff_kee"] ) {
    my["kee"] = my["eff_kee"];
    if( my["eff_kee"] < my["max_kee"] )  { my["eff_kee"] ++; update_flag++; }
  } else update_flag++;

  my["sen"] += my["con"] + my["mana"] / 8;
  if( my["sen"] >= my["eff_sen"] ) {
    my["sen"] = my["eff_sen"];
    if( my["eff_sen"] < my["max_sen"] )  { my["eff_sen"] ++; update_flag++; }
  } else update_flag++;

  if( my["max_atman"] && my["atman"] < my["max_atman"] ) {
    my["atman"] += (int)this_object()->query_skill("magic", 1) / 2;
    if( my["atman"] > my["max_atman"] ) my["atman"] = my["max_atman"];
    update_flag++;
  }

  if( my["max_force"] && my["force"] < my["max_force"] ) {
    my["force"] += (int)this_object()->query_skill("force", 1) / 2;
    if( my["force"] > my["max_force"] ) my["force"] = my["max_force"];
    update_flag++;
  }

  if( my["max_mana"] && my["mana"] < my["max_mana"] ) {
    my["mana"] += (int)this_object()->query_skill("spells", 1) / 2;
    if( my["mana"] > my["max_mana"] ) my["mana"] = my["max_mana"];
    update_flag++;
  }

  if( my["max_officer_power"] && my["officer_power"] < my["max_officer_power"] ) {
    my["officer_power"] += this_object()->query_skill("be-officer",1) / 2;
    if( my["officer_power"] > my["max_officer_power"] ) my["officer_power"] = my["max_officer_power"];
    update_flag++;
  }
  return update_flag;
}
int cal_damage(object me,int damage)
{
    int armor;

    armor=me->query_temp("apply/armor");
    if(me->is_fighting()){
      if(damage-armor >0)
        return damage-armor;
      else
        return 0;
    }
    else{
      if(damage-armor>0)
        return damage-armor;
      else
        return damage;
    }
}
