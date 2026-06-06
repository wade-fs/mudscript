#include <ansi.h>

inherit ITEM;
string get_file_item();

void create()
{
        set_name(HIR"新年禮物"NOR, ({ "gift", }) );
        set("long","新年禮物，可以打開(open)他。\n");
        set("unit", "顆");
       set("value", 100);
			 set("no_get",1);
			 set("no_give",1);
			 set("no_put",1);
			 set("no_auc",1);
       set("no_save",1);
	setup();
}
void init()
{
  add_action("do_open","open");
}
int do_open(string arg)
{
  int rand ;
  string str;
  object me = this_player();
  object money;
  if(arg != "gift") return 0;
  rand = random(100);
  switch(rand)
  {
    case 0..30:
    str = "哈哈哈，我得到各色藥丸啦。\n";
    money = new("/open/fire-hole/obj/b-pill.c");
    money->set_amount(10);
    money->move(me);
    money = new("/open/fire-hole/obj/g-pill.c");
    money->set_amount(10);
    money->move(me);
     money = new("/open/fire-hole/obj/k-pill.c");
    money->set_amount(10);
    money->move(me);
     money = new("/open/fire-hole/obj/p-pill.c");
    money->set_amount(10);
    money->move(me);
     money = new("/open/fire-hole/obj/r-pill.c");
    money->set_amount(10);
    money->move(me);
     money = new("/open/fire-hole/obj/w-pill.c");
    money->set_amount(10);
    money->move(me);
      money = new("/open/fire-hole/obj/y-pill.c");
    money->set_amount(10);
    money->move(me);
 
    break;
    case 31..35:
    str = "哈哈哈哈，我的倉庫空間多一格了。\n";
    "/adm/daemons/saveeqd"->set("id",this_player()->query("id"));
    "/adm/daemons/saveeqd"->restore();

    "/adm/daemons/saveeqd"->add("max_store",1);
    "/adm/daemons/saveeqd"->save();
    break;
    case 36..60:
    str = "哈哈哈，我得到十顆鑽石啦。\n";
    money = new("/obj/money/diamond");
    money->set_amount(10);
    money->move(me);
    break;
    case 61..85:
    str = "超爽的，得到一個替身！\n";
    me->add("standby",1);
    break;
    case 86..90:
    str = "超爽的，基本內功\昇高五級\n";
    me->set_skill("force",me->query_skill("force",1) +5);
    break;
    case 91..95:
    str = "超爽的，跳躍閃躲之術昇高五級！\n";
    me->set_skill("dodge",me->query_skill("dodge",1) +5);

    break;
    case 96..99:
    money = new (get_file_item());
    money -> move(me);
    str = "超爽的，我拿到"+money->name()+"！\n";


    break;

    default:
    str = "幹，見鬼了！\n";

  }
  me->delete_temp("last_channel_msg");
    CHANNEL_D->do_channel(this_player(),"chat",str);
  log_file("2010-gift",me->name() + str+"\n");  
  destruct(this_object());
  return 1;
}
string *filter_items = ({
    "light-emblem.c",
    "light_emblem.c",
    "emperor-stone.c",
    "emperor_stone.c",
    "fire-feather.c",
    "fire_feather.c",
    "free-shells.c",
    "free_shells.c",
    "kai-jade.c",
    "kai_jade.c",
    "forest-diamond.c",
    "forest_diamond.c",
    "fox-order.c",    
    "fox_order.c",
    "plum-wind.c",
    "plum_wind.c",
    "tender-charm.c",
    "tender_charm.c",
    "surname-yin.c",
    "surname_yin.c",
	"sakura-yin.c",
	"huai-yin.c",
    "black-crystal.c",
    "black_crystal.c",
    "banana-doll.c",
    "banana_doll.c",
    });
string get_file_item()
{
    string *files,file,dir;
    string *dirs = ({
        "obj10",
        });
    dir = "/open/sky/"+dirs[random(sizeof(dirs))]+"/";
    files = get_dir(dir);
    file = files[random(sizeof(files))];
    if(member_array(file,filter_items) != -1 )
	return get_file_item();
	return dir+file;
}

