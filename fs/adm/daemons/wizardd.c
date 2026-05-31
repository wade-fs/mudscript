
#include <localtime.h>

#define WIZARD_DATA DATA_DIR + "wizard"

inherit F_SAVE;
inherit F_DBASE;

void clear_week_record();

void create()
{
  mixed ltime;
	seteuid(geteuid());
  ltime = localtime(time());

	restore();
  if(ltime[LT_HOUR] == 6 &&
      ltime[LT_WDAY] == 2)
  clear_week_record();
}

string query_save_file() { return WIZARD_DATA; }

void update_record(string id)
{
	seteuid(geteuid());

  add(id+"/all",1);
  add(id+"/week",1);
 save(); 
}
void clear_week_record()
{
  foreach(string id,mixed d in query_entire_dbase())
  {
    delete(id+"/week");
  }
  save();
}
