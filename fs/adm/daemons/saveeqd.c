inherit F_SAVE;
inherit F_DBASE;
void checkStatus();

int isExist(object obj);
void create()
{
  seteuid(ROOT_UID);
}
int sort_item(string item1,string item2)
{
 return strcmp(item1,item2);
}
mixed sort(mixed items)
{
  string *sorted_item;
  mixed *new_item;
  sorted_item = sort_array(keys(items),(:sort_item:));
  new_item = ({});
  foreach(string item in sorted_item)
  {
    new_item += ({ ([ item : items[item] ]) });
  } 
  return new_item;
}  

string list()
{
  string str;
  mixed items;
  int i;
  checkStatus();
  str = sprintf("你目前儲存的物品如下(%d/%d)：\n",sizeof(query("objects")),query("max_store"));
   if(!sizeof(query("objects"))) {
     return str;
  }
 
  i = 0;
  items = sort(query("objects"));
  foreach(mixed item in items )
  {
    string file;
    int amount;
    object obj ;
    file = keys(item)[0];
    amount = item[file];
    obj = load_object(file);

    if(!obj) continue;
    i++;
    str += sprintf("[%2i] [%|15s] %s%s\n",
          i,
          CHINESE_D->chinese_number(amount) + obj->query("unit"),
          obj->name(),
          (wizardp(this_player())) ? "("+base_name(obj)+")" : ""
        );
  }
  return str;
}
// 傳入列表的第幾個, 會回傳拿出來什麼東西
object take(int which)
{
  mixed items,old_items;
  object obj;

  checkStatus();
  items = sort(query("objects"));
  old_items = query("objects");
  for(int i = 0 ; i < sizeof(items) ; i++)
  {
    if(which == i + 1)
    {
      mixed item;
      string file;
      int amount;
      item = items[i];
      file = keys(item)[0];
      amount = item[file];
      obj = new(file);
      // pill 類的會一次全拿出來，其他的一件一件拿。
      if(!obj->query_amount())
      {
        old_items[file] -= 1;
        if(old_items[file] == 0)
        {
          map_delete(old_items,file);
        }
      }
      else
      {
        obj->set_amount(amount);
        map_delete(old_items,file);
      }
      
//      obj->move(this_player());
      break;
    }
  }
  set("objects",old_items);
  save();
  return obj;
}
// 傳入要存的物件
int store(object obj)
{
  int amount;
  mixed items;
  checkStatus();
  
  items = query("objects");
  amount  = obj->query_amount();
  if(isExist(obj) && query("max_store") <= sizeof(items))
    return 0;

  if(!amount) amount  = 1;

  if(undefinedp(items) || !sizeof(items)) items = allocate_mapping(0);
  if(undefinedp(items[base_name(obj)]))
    items[base_name(obj)] = amount;
  else
    items[base_name(obj)] += amount;
  set("objects",items);
  save();
destruct(obj);
  return 1;
}
// 查看看是不是已經在品項裡面了。
int isExist(object obj)
{
  mixed items;
  items = query("objects");
  if(undefinedp(items) || !sizeof(items)) return 1;
  if(undefinedp(items[base_name(obj)])) return 1;
  return 0;

}
void checkStatus()
{
  if(query("id") != this_player()->query("id"))
  {

    dbase = ([]);
    set("id",this_player()->query("id"));

    restore();
  }
 
  if(!query("max_store"))
    set("max_store",5);
}
int queryMaxStore()
{
checkStatus();
return query("max_store");
}
int addMaxStore()
{
  checkStatus();
  if(query("max_store") == 20) return 0;
  add("max_store",1);
  save();
  return 1;
}
int restore()
{
  string id ; 
  if(!(id = query("id"))) return 0;
  return ::restore();
}

int save()
{
  string id ; 
  if(!(id = query("id"))) return 0;
  return ::save();
}

string query_save_file()
{
  string id ; 
  id = query("id");
   if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "saveeq/%c/%s", id[0], id);

}
