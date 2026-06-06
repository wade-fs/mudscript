#include <mudlib.h>
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIC + "遠程狙擊槍" + NOR , ({"Kill Gun" , "gun"}));
  set("long",
      "專為遠程狙擊設計, 命中率奇高, 僅有狙擊手能使用。\n");
  set_weight(1);
  set("unit", "挺");
  seteuid(getuid());
}

void init()
{
  add_action("fire", "shot");
}

int query_auto_load()
{
return 1;
}

int fire(string str)
{
  object target,targetenv;
  
 if(this_player()->query("id") !="ranko")
  return notify_fail("你不會使用這挺需要高度技術的槍。\n");
  if(!str || str == "") 
    {
      write(HIW + "你試射了一槍來測試彈道, 看來這槍正處在最佳的狀況。\n" + NOR);
      tell_room(environment(this_player()), HIC+this_player()->query("name")
                +HIW"舉起狙擊槍試射了一槍, 看來又有人要被暗算了。\n" + NOR,
                ({this_object(), this_player()}));
      return 1;
    }
  target=present(str,environment(this_player()));
  if(!target) target = find_living(str);
  if(!target) {
  write(HIC+"大近視眼﹐看清楚目標再射擊﹗\n"+NOR);
  return 1;}
  targetenv=environment(target);
  
  
  if(target != this_player())
   write( HIW + "妳瞄準" + HIC + (string)target -> query("name") + HIW"的眉心擊出一彈"
         + ", "NOR + RED"準確地貫穿了他的腦袋﹗\n" + NOR );
  else
  {
  write("遠程狙擊槍不能用來自殺。\n");
  return 1;
  }
  
  tell_room(environment(this_player()),""+HIC
            +(string)this_player()->query("name")
            +HIW"舉起狙擊槍, 瞄準"HIC + (string)target -> query("name")
            +HIW"的眉心準確地發出一顆子彈﹗\n" + NOR , ({this_player() , target}));

  tell_room(environment(target) , HIW + "忽然一聲槍響, 只見一顆子彈準確地貫穿了" + HIC
            + (string)target -> query("name")
            + HIW"的額頭正中央﹗\n" + NOR , ( { this_player() , target } ) );
     
  tell_object(target,
              HIW + "忽然一聲槍響, 一顆子彈已經貫穿了你的額頭正中央﹗\n" + NOR +
              "( 你"+RED"受傷過重﹐已經有如風中殘燭﹐隨時都可能斷氣。" + NOR
              +" )\n");
  target -> set("env/immortal" , 0);
  this_object() -> destruct();
  target -> die();
   
  return 1;
}


