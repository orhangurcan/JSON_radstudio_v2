//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JSON.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// Create the outer JSON object which parents the others.
  TJSONObject *o = new TJSONObject();
  __try {
		// Create the books object, which contains the array of books...
		TJSONArray *a = new TJSONArray();

		// add the array to the object.
		o->AddPair("books",a);

		// Create the first book
		TJSONObject *book = new TJSONObject();
		book->AddPair( new TJSONPair("title","Zen") );
		book->AddPair( new TJSONPair("subtitle","and The art of motorcycle maintenance.") );
		book->AddPair( new TJSONPair("author","Robert M Pirsig") );
		book->AddPair( new TJSONPair("isbn","9780061908019") );
		// Add the book to the array
		a->AddElement(book);

		// Create the second book
		book = new TJSONObject();
		book->AddPair( new TJSONPair("title","Coding in Delphi") );
		book->AddPair( new TJSONPair("subtitle","") );
		book->AddPair( new TJSONPair("author","Nick Hodges") );
		book->AddPair( new TJSONPair("isbn","978-1941266038") );
		// Add the book to the array
		a->AddElement(book);
	}
  __finally
	{
	  Memo1->Lines->Text = o->ToString();
	  o->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  TJSONObject *o = (TJSONObject*) TJSONObject::ParseJSONValue(TEncoding::ASCII->GetBytes(Memo1->Lines->Text),0);
  __try {
	TJSONArray *a = (TJSONArray*) o->Get("books")->JsonValue;
	for (int idx = 0; idx < a->Size(); idx++) {
	  TJSONObject *book = (TJSONObject*) a->Get(idx);
	  for (int idy = 0; idy < book->Count; idy++) {
		ShowMessage( book->Pairs[idy]->JsonString->ToString() + ':' +
					 book->Pairs[idy]->JsonValue->ToString() );
	  }
	}
  }
  __finally {
	o->Free();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	// Create the outer JSON object which parents the others.
  TJSONObject *o = new TJSONObject();
  __try {

		TJSONArray *a = new TJSONArray();
		o->AddPair("mode",2);
		o->AddPair("speed",1000);
		o->AddPair("position",500);
	}

  __finally
	{
	  Memo1->Lines->Text = o->ToString();
	  o->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
//TJSONObject *JSON = (TJSONObject*)TJSONObject::ParseJSONValue(myJSON);
  TJSONObject *JSON = (TJSONObject*) TJSONObject::ParseJSONValue(TEncoding::ASCII->GetBytes(Memo1->Lines->Text),0);
  __try {

  TJSONPair *mode_ = JSON->Get("mode");
  TJSONPair *speed_ = JSON->Get("speed");
  TJSONPair *position_ = JSON->Get("position");

  String value = mode_->JsonValue->ToString();
  String value2 = speed_->JsonValue->ToString();
  String value3 = position_->JsonValue->ToString();
  ShowMessage(value);
  ShowMessage(value2);
  ShowMessage(value3);

  }
  __finally {
	JSON->Free();
  }
}
//---------------------------------------------------------------------------

