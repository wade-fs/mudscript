// 為保障doctor權利..只允許給doctor..check
// 一次只能練製二粒,而且需要最高的醫術 cure 120 及 godcure 100才能練製!!!
//排版 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("地靈草",({"ground item","item"}));
  set("long",
    "此乃崑崙山上最為出名的三聖草之一「地靈草」，此草吸盡大地精華，然夠盡解世間百毒，\n"+
    "此物須經過醫者精湛的醫術方可提煉。\n");
  set("unit", "棵");
  set("base_unit", "棵");
  set("no_sell",1);
  set("value",2500);
  set("base_weight", 50);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("check_item","check_item");
  }
}

int check_item(string arg)
{
  int cure;
  string str;
  if( (arg=="item" || arg=="super item") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor")
      return notify_fail("你職業不是醫者無法將藥株製成藥丸!!\n");
    cure = user->query_skill("cure"); //估計值為160
    if( cure > 159)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      cure = 2;//一次最多只能練出二粒
      ob=new("/open/doctor/pill/gnd_pill");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將地靈草製成靈丹。\n", user);
      if( user->query("force") < 400 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-400);
      ob->move(this_player());
      ob->add_amount((int)cure);
      cure=80;
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random(cure)); //估計值為80
      else
        user->improve_skill("cure",random((int)cure/4)+1); //估計值為1~21
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將地靈草製成靈丹。\n", user);
    return 1;
  }
  return 0;
}
