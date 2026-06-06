inherit ITEM;

void create()
{
  set_name("字石", ({ "gold key","key" }) );
  set("unit", "粒");
  set("long", "一粒超大的石頭，上面有神秘數字。\n");
  set("stone",1);
  set("no_get",1);
  set("no_drop",1);
  set("no_sac",1);
  setup();
}
void init()
{
  add_action("do_push","push");
}
int do_push(string arg)
{
  object obj;
  string dir;
  string name;
  if(!arg || sscanf(arg,"%s to %s",name,dir) != 2)
  {
    write("請用 push stone to [east/west/south/north]\n");
    return 1;
  }
  if(!environment(this_player())->query("exits/"+dir))
  {
    write("方向不對！\n");

    return 1;  
  }
  obj = present(name,environment(this_player()));
  if(!obj)
  {
    write("這裡沒有這項東西");
    return 1;
  }
  if(!obj->query("stone"))
  {
    write("這個不是石頭啊！");
    return 1;
  }
  if(obj->query("no_push"))
  {
    write("這是基準石,不能動！");
    return 1;
  }

  obj->move(load_object(environment(this_player())->query("exits/"+dir)));

  message_vision("$N把$n往"+DIR_D->cdir(dir)+"推去。\n",this_player(),obj);
  return 1;
}
