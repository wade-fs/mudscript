// made by ccat
// 為保障doctor權利..只許給doctor..check
// 道士可以煉丹.所以..將super item及force item開放給taoist
//排版 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("天山雪蓮", ({"force item","item"}) );
  set("long",
    "此物乃蜀中將軍自天山絕頂採來之神藥，可以瞬間恢復部份內力。此藥需經藥師調配\n"+
    "(check_item force item)，方得食用(eat pill)。\n");
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
  if( (arg=="item" || arg=="force item") && (query("unit") == "棵") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor" && user->query("class")!="taoist" && !wizardp(user))
      return notify_fail("你職業不是醫者或道士無法將藥株製成藥丸!!\n");
    cure = user->query_skill("cure"); //估計值為160
    cure = cure /4; //估計值為40
    if( cure > 14)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      if(user->query("class")=="taoist")
      cure=cure/2;
      ob=new("/open/doctor/pill/ff_pill");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將天山雪蓮製成靈丹。\n", user);
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      ob->move(this_player());
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure)); //估計值為0~40
      else
        user->improve_skill("cure",random((int)cure/4)+1); //估計值為1~11
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將雪蓮製成靈丹。\n", user);
    return 1;
  }
  return 0;
}
