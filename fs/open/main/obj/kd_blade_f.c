// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.

#include <ansi.h>
#include <weapon.h>
#include <combat.h>
inherit BLADE;
inherit SSERVER;
object user;
int sp;
void create()
{
     set_name("屠龍刀",({"dragon blade","blade"}) );
     set_weight(40000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","一股殺氣撲面而來,刀面閃爍凜凜青光,這就聞名天下的屠龍"+
            "寶刀.\n");
            set("unit", "件");             
            set("value",5000);
            set("no_sell",1);
            set("no_steal",1);
            set("no_save", 1);
            set("no_put",1);
            set("rigidity",200);
            set("sharp",1);
            set("material","crimsonsteel");
           }         
        init_blade(100);
        setup();
}

void init()
{
     add_action("do_drop","drop"); 
     add_action("do_auc","auc"); 
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}

int do_wield(string str)
{ 
     int my_cor,my_exp;
     ::wield();
     if( query("equipped") ) 
     {
        user = this_player();     // 取得使用者
        my_cor = user->query_cor(1);
       my_exp = user->query("combat_exp",1);
              //為表示神兵利器所以調高使用調件
          if( my_exp * my_cor < 10000000 )
        {
          message_vision("$N的膽識與經驗,並不足以號令屠龍刀.\n",user);
          set_name("屠龍刀",({"dragon blade","blade"}) );
          set_heart_beat(0);
        }else{
          message_vision(HIY"屠龍刀感受到$N的膽識,泛起一層金光.\n"NOR,user);
          set_name(HIY"屠龍刀"NOR,({"dragon blade","blade"}) );
          sp = my_cor;
          set_heart_beat(1);
        }
     } 
}

int do_drop(string str)
{  
   if( str=="all" || str=="blade" || str=="dragon-blade")  
     if( query("equipped") )
     {
        set_name("屠龍刀",({"dragon blade","blade"}) );
        set_heart_beat(0);
     }    
}

int do_give(string str)
{  
   if( str=="all" || str=="blade" || str=="dragon-blade")
     if( query("equipped") )
     { 
        set_name("屠龍刀",({"dragon blade","blade"}) );
        set_heart_beat(0);
     }
}

int do_unwield(string str)
{
   if( str=="all" || str=="blade" || str=="dragon-blade")
     if( query("equipped") )
     {
        message_vision("$N將屠龍刀放回刀鞘.\n",user);
        set_name("屠龍刀",({"dragon blade","blade"}) );
        set_heart_beat(0);
     }   
} 

int do_auc(string str)
{
   if( str=="all" || str=="blade" || str=="dragon-blade")
     if( query("equipped") )
     { 
        set_name("屠龍刀",({"dragon blade","blade"}) );
        set_heart_beat(0);
     } 
} 


