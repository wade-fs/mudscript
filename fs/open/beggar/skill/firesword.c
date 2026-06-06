// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
object user;
int sp,max;
void create()
{
     set_name( "火龍劍",({"fire dragon sword","sword"}) );
     set_weight(7500);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","能於戰鬥中,招換出火燄的魔法劍.\n"
                      +"發射火燄: sword_fire,檢查威力:sword_check\n"
                      +"會於戰鬥中自動集氣,集氣越久,威力越強.");
            set("unit", "件");             
            set("value",20000);
            set("material","steal");
            set("wield_msg", "$N從劍鞘裡抽出火龍劍.\n");
            set("unwield_msg", "$N把火龍劍插回劍鞘裡.\n");
           }         
        init_sword(55);
        setup();
}

void init()
{
     add_action("do_wield","wield");
     add_action("do_check","sword_check");
     add_action("do_fire","sword_fire");
}

int do_wield(string str)
{ 
     ::wield();
     if( query("equipped") ) 
     {
        user = this_player();     // 取得使用者
        sp = 0;
        max = user->query_skill("sword",1);
        if(max > 70)  max=70;
        set_heart_beat(1);
     } 
}
int do_check()
{
 
 if( query("equipped") )
   write("火龍劍儲存的殺氣有 "+sp+" 層.\n");
 return 1;
}
void heart_beat()
{
  if( user->is_fighting() && query("equipped") && sp < max )
  {
   sp++; 
  }
  return;
}

int do_fire()
{
  object *enemy;
  int i,pp;
  
  if( max < 15)
  {
    write("你的劍術太低,無法呼喚火燄.\n");
    return 1;
  }
  
  if( user->is_fighting() && query("equipped") )
  {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    if( environment(user) == environment(enemy[i]) )
    { 
       if( random(250)+max > enemy[i]->query_skill("dodge") )
      {
        if( sp < 2)
        {
          message_vision("一點小火星從$N手中長劍飛出,射向$n,但是完全沒"
                            +"有造成損傷!!!\n",user,enemy[i]);
          sp=0;
          return 1;
        }else if( sp < 10 )
        {
          message_vision(HIR+"一顆小火球從$N手中長劍飛出,射向$n!!!\n"
                         +NOR,user,enemy[i]);
          pp = sp;
        }else if( sp < 20 )
        {
          message_vision(HIR+"$N手中長劍往地上一指,熊熊火燄倏然從地底冒"
                         +"出,燃燒著$n!!!\n"+NOR,user,enemy[i]);
          pp=sp*2;               
          enemy[i]->apply_condition("burn",(int)sp*1.5);
        }else if( sp < 30)
        {
          message_vision(HIR+"$N手中長劍一揮,只見天上地上,到處火燄一片,"
                      +"$n陷入了熊熊火海中!!!\n"+NOR,user,enemy[i]);
          pp=sp*3;
          enemy[i]->apply_condition("hellfire",(int)sp/2);
        }else if( sp < 40)
        {
          message_vision(HIR+"$N祭起長劍,只見四週景物開始淡去,火燄從朦朧"
                            +"中突然透出,一招天火燎原結實的炸在$n身上!!!\n"
                            +NOR,user,enemy[i]);
          pp=sp*4;
          enemy[i]->apply_condition("hellfire",(int)sp/2);                  
        }else{
          message_vision(HIR+"$N舉手一揚,只見$n忽陷火燄漩渦,一條黑色火龍"
                            +"破地而出,一頭撞上了$n!!!\n"
                            +NOR,user,enemy[i]);
          pp=sp*5;
          enemy[i]->apply_condition("hellfire",(int)sp/2);
        } 
        sp=0;
        enemy[i]->receive_damage("kee",pp,user);
        COMBAT_D->report_status(enemy[i], 0);
      }else
      {
        message_vision(HIR+"$N嘗試招喚火燄...但是沒有成\功\...\n"
                      +NOR,user);         
        sp=sp*0.7;
      }
     }
   }
  return 1;
}  
