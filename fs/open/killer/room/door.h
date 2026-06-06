
#define DOOR_LOCK       2
#define DOOR_CLOSE      1
#define DOOR_OPEN       0
#define NOKEY           0

int look_door(string dir,string str)
{
  object room;
  int status;
  string door;
  room = this_object();
  if (str == "door")
  {
    status = (int)room->query("door/"+dir+"/status");
    if (status == DOOR_LOCK ) 
    {
      if (!(room->query("door/"+dir+"/lock"))) door="這"+(string)room->query("door/"+dir+"/name")+"正鎖著！\n";
      else door=(string)room->query("door/"+dir+"/lock");
    }
    if (status == DOOR_CLOSE) 
    {
      if (!(room->query("door/"+dir+"/lock"))) door="這"+(string)room->query("door/"+dir+"/name")+"是關著的。\n";
      else door=(string)room->query("door/"+dir+"/close");
    }
    if (status == DOOR_OPEN ) 
    {
      if (!(room->query("door/"+dir+"/lock"))) door="這"+(string)room->query("door/"+dir+"/name")+"是開著的。\n";
      else door=(string)room->query("door/"+dir+"/open");
    }  
    write (door);
    return 1;
  }
  else return 0; 
}


int open_door(string dir,string str)
{
  object room;
  int status;
  string relation,connect;
  room = this_object();
  connect  = (string)room->query("door/"+dir+"/connect");
  if ( str == "door" )
  {
    status = (int)room->query("door/"+dir+"/status");
    if (status == DOOR_LOCK ) write((string)room->query("door/"+dir+"/name")+"被鎖的很緊，你無法打開它！\n");
    if (status == DOOR_OPEN ) write((string)room->query("door/"+dir+"/name")+"己經是開著的了。\n");
    if (status == DOOR_CLOSE) 
    {
      write("你把"+(string)room->query("door/"+dir+"/name")+"打開！\n");
      say (this_player()->query("name")+"把"+(string)room->query("door/"+dir+"/name")+"打開！\n");
      room->set("exits/"+dir , (string)room->query("door/"+dir+"/connect"));
      room->set("door/"+dir+"/status" , DOOR_OPEN);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_OPEN);
        connect->set("exits/"+relation , (string)connect->query("door/"+relation+"/connect"));
      }
    }
    return 1;
  }
  return 0;
}

int close_door(string dir,string str)
{
  object room;
  int status;
  string relation , connect;
  room = this_object();
  relation = (string)room->query("door/"+dir+"/relation");
  connect  = (string)room->query("door/"+dir+"/connect");
  if ( str == "door" )
  {
    status = (int)room->query("door/"+dir+"/status");
    if (status == DOOR_LOCK || status == DOOR_CLOSE) 
      write((string)room->query("door/"+dir+"/name")+"早己關著了。\n");
    if (status == DOOR_OPEN ) 
    {
      write("你把"+(string)room->query("door/"+dir+"/name")+"關上。\n");
      say (this_player()->query("name")+"把"+(string)room->query("door/"+dir+"/name")+"關上。\n");
      room->delete("exits/"+dir );
      room->set("door/"+dir+"/status" , DOOR_CLOSE);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_CLOSE);
        connect->delete("exits/"+relation );
      }
    }
    return 1;
  }
  return 0;
}

int lock_door(string dir,string str)
{
  object room,me,key;
  int status;
  string connect,relation;
  if (str != "door") return notify_fail("你要鎖什麼？\n");
  key = this_object();
  me = this_player();
  room = environment(me);
  if (!room->query("door/"+dir)) return 0;
  connect =  (string)room->query("door/"+dir+"/connect");
  status = (int)room->query("door/"+dir+"/status");
  if (status == DOOR_OPEN ) write("請先關門\n");
  if (status == DOOR_LOCK ) write("它己經上鎖了！沒必要鎖兩層吧……\n");
  if (status == DOOR_CLOSE)
  {
    if( (string)key->query("keyflag") == (string)room->query("door/"+dir+"/key") )
    {
      write((string)key->query("lock"));
      room->set("door/"+dir+"/status",DOOR_LOCK);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_LOCK);
      }
      return 1;  
    }
    else
    {
      write("你的"+(string)key->query("name")+"不能把這個門上鎖\n");
      return 0;
    }
  }  
}

int unlock_door (string dir,string str)
{
  object room,me,key;
  int status;
  string connect,relation;
  if (str != "door") return notify_fail("你要開什麼？\n");
  key = this_object();
  me = this_player();
  room = environment(me);
  if (!room->query("door/"+dir)) return 0;
  connect =  (string)room->query("door/"+dir+"/connect");
  status = (int)room->query("door/"+dir+"/status");
  if (status == DOOR_OPEN ) write ("它己經打開囉！\n");
  if (status == DOOR_CLOSE) write ("它沒上鎖啊！\n");
  if (status == DOOR_LOCK )
  {
    if( (string)key->query("keyflag") == (string)room->query("door/"+dir+"/key") )
    {
      write((string)key->query("unlock"));
      room->set("door/"+dir+"/status",DOOR_CLOSE);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_CLOSE);
      }
      return 1;  
    }
    else
    {
      write("你的"+(string)key->query("name")+"無法打開這個鎖\n");
      return 0;
    }
  }  
}

