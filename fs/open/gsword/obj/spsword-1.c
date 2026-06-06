#include <weapon.h>
inherit SWORD;
object ob;
object *target;
object ob1=this_object();
int sp_value;
int sp_hit;
void create()
{
	set_name("赤麟ソ劍",({"blood_sword"}) ); // 絕對不要單獨 sword
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
 set("long","這是一把由血獸的血所粹鍊出來的一把邪惡之劍,他會幫你一起打擊對手,
            相傳得此劍者也能一統江湖,所以這也是綠毛老祖最愛的一把劍...");
	set("unit","件");
	set("value", 1000);
	set("material","steel");
	set("no_sell", 1);
	}
	init_sword(60);
	setup();
}

void init()
{
     add_action("do_drop","drop"); 
     add_action("do_auc","auc"); 
     add_action("doo_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}

int doo_wield(string str)
{
    int max_sp_hit;
    max_sp_hit=250;
    ob=this_player();
    sp_value=(ob->query_spi()+ob->query_kar())*2+ob->query("bounds")/100+
    ob->query("combat_exp")/1000;
    sp_hit=ob->query("MKS")/1000+random(80);
    if(str!="blood_sword")
      return 0;
    else 
     ::wield();   
    if( sp_hit >max_sp_hit)
       sp_hit=max_sp_hit;
    if(ob1->query("equipped"))
    {
       set_heart_beat(1);
       message_vision("$N手握赤麟 ,復仇怨念衝激使$N全身漲紅 ,隱約散發出一股肅殺之氣 .\n",this_player());
       return 1;
     }     
    
    return 0;
  
  
}
int do_drop(string str)
{
    if(str == "blood_sword" || str=="all")
    {
      set_heart_beat(0);
       message_vision("$N將赤麟放下 ,逐漸恢復心智.\n",this_player());
    }
}    
int do_give(string str)
{
    if(str == "blood_sword" || str=="all")
    {
      set_heart_beat(0);
       message_vision("$N將赤麟放下 ,逐漸恢復心智..\n",this_player());
     }
}
int do_unwield(string str)
{
    if(str == "blood_sword" || str=="all")
    {
       set_heart_beat(0);
       message_vision("$N將赤麟放下 ,逐漸恢復心智..\n",this_player());
     }
}                       
int do_auc(string str)
{
    if(str == "blood_sword" || str=="all")
    {
       set_heart_beat(0);
       message_vision("$N將赤麟放下 ,逐漸恢復心智..\n",this_player());
    }
}                                                         

void heart_beat()
{
  int *target,i;
if(!ob) return ;
  target=ob->query_enemy();
if(sizeof(target) == 0) return ;
  i=random(sizeof(target));
  if( ob1->query("equipped") )
  if( ob->is_fighting() )
  if( sp_value > random(1500) )
    {
     message_vision("赤麟幻化成一血獸 ,啃噬著$N的身驅\n ",target[i]);
     target[i]->add("kee",-sp_hit);
     }
  return;
 }        
      
