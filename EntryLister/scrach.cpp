#include "EntryLister.h"
//TODO: csak_belepot megszamolni

int count = 0;
f = ifstream(fp);
EntryLister el(f);

if(el.getFirst().get()->getLeave().isvalid()){
cout << el.linecount-1  << " " << el.getFirst().get()->toString() << endl;
}

for(;!el.end();el.next()){
if(!el.getSecond().get()->getLeave().isvalid()){
++count;
}
if(el.isTheSame()){
if(el.getFirst().get()->getLeave().isvalid() && el.getSecond().get()->getLeave().isvalid()){
cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
}
else if (el.getSecond().get()->getLeave().isvalid()){
--count;
}
}
else if((!el.isTheSame())){
if (el.getSecond().get()->getLeave().isvalid()) {
cout << el.linecount << " " << el.getSecond().get()->toString() << endl;
}
}
}
cout << count << endl;

f.close();