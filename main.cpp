#include <iostream>
#include <vector>

using namespace std;

// Базовый объект
class BaseObject
{
public:
    string sCaption; // название
    int tCreateAt; // номер тика создания
    int iVolume; // занимаемый объемt
    float nBasePrice;

    BaseObject(int tCreateAt)
    {
        this->sCaption = "createAt";
        this->iVolume = 0;
        this->nBasePrice = 0;
        this->tCreateAt = tCreateAt;
    }

    virtual ~BaseObject() {}



    virtual BaseObject *fClone() const
    {
        return new BaseObject(*this);
    }

    // тик объекта элмент жизненного цикла
    virtual void fTick()
    {
        cout << "Hi! Im " << this->sCaption << "\r\n";
    }

    virtual void fPrint()
    {
        cout << "hi " << this->sCaption << "\r\n";
    }

};


class Core
{
public:
    int iCounter;
    vector<BaseObject *> aObjects;

    Core()
    {
        this->iCounter = 0;
    }

    ~Core()
    {
        for (unsigned int i = 0; i < this->aObjects.size(); i++) {
            delete aObjects[i];
        }
    }

    void fAdd(BaseObject *object)
    {
        cout << "add " << object->sCaption << "\r\n";
        this->aObjects.push_back(object);
    } // fAdd

    void fTick()
    {
        this->iCounter++;
        cout << "Core tick " << this->iCounter << "\r\n";

        for (unsigned int i = 0; i < aObjects.size(); i++) {
            aObjects[i]->fTick();
        }
    } // fTick()

};


class BaseFabric: public BaseObject
{
protected:
    Core *core;

public:
    BaseFabric(int iCreateAt, Core *core): BaseObject(iCreateAt)
    {
        this->core = core;
        this->sCaption = "fabric";
    }

    ~BaseFabric() {}

    virtual void fTick()
    {
        cout << "Fabric tick" << "\r\n";

        this->core->fAdd(new BaseObject(this->core->iCounter));
    }
};

// Хранилище
class BaseStore: public BaseObject
{
protected:
    vector<BaseObject *> aObjects;
public:

    int iCapacity; // вместимость

    BaseStore(int iCreateAt): BaseObject(iCreateAt)
    {
        this->sCaption = "BaseStore";
    }

    virtual BaseStore *fClone() const
    {
        return new BaseStore(*this);
    }

    virtual bool fAdd(BaseObject *object)
    {
        bool ok = true;

        if (this->fLength() < this->iCapacity) {
            this->aObjects.push_back(object);
        } else {
            ok = false;
        }

        return ok;
    }

    virtual void fRemove(int id)
    {
        this->aObjects.erase(this->aObjects.begin() + id);
    }

    virtual void fRemove(string caption)
    {
        //this->aObjects.erase(this->aObjects.begin()+id);
    }

    unsigned int fLength()
    {
        return this->aObjects.size();
    }
};

// деньги на счете
class MoneyCache
{
private:
    float nMoney;
public:
    MoneyCache(float nMoney)
    {
        this->nMoney = nMoney;
    }

    void fAdd(float nMoney)
    {
        this->nMoney = this->nMoney + nMoney;
    }

    bool fTakeSafe(float nMoney)
    {
        bool ok = true;

        if (nMoney > this->nMoney) {
            ok = false;
        } else {
            this->nMoney = this->nMoney - nMoney;
        }

        return ok;
    }

    void fTake(float nMoney)
    {
        this->nMoney = this->nMoney - nMoney;
    }

    float fBalance()
    {
        return this->nMoney;
    }
};

// продавец
class BaseSeller: public BaseObject
{
protected:
    MoneyCache *money;
    float nPrice;
    BaseObject *obj;
public:

    BaseSeller(int iCreateAt, float nPrice, BaseObject *obj): BaseObject(iCreateAt)
    {
        this->money = new MoneyCache(0);
        this->nPrice = nPrice;
        this->obj = obj;
    }

    // продать
    virtual BaseObject *fSale(int iCreateAt, float nPrice)
    {
        BaseObject *resp;

        if (nPrice == this->nPrice) {
            this->money->fAdd(this->nPrice);
            resp = obj->fClone();
        }

        return resp;
    }

    float fBalance()
    {
        return this->money->fBalance();
    }

    ~BaseSeller()
    {
        delete money;
        delete obj;
    }
};

// главный порцесс системы
class TProcess
{
protected:
    Core *core;
    MoneyCache *money;
public:
    TProcess()
    {
        this->core = new Core();
        this->money = new MoneyCache(1000);
    }
    ~TProcess()
    {
        delete this->core;
    }

    TProcess *fStart()
    {
        cout << "fStart \r\n";
        return this;
    }
    TProcess *fFinish()
    {
        cout << "fFinish \r\n";
        return this;
    }

    TProcess *fBayIngredients()
    {
        cout << "fBayIngredients \r\n";
        return this;
    }

    TProcess *fMakeChoco()
    {
        fBayIngredients();
        cout << "fMakeChoco \r\n";
        fPushToStore();
        return this;
    }

    TProcess *fPushToStore()
    {
        cout << "fPushToStore \r\n";
        return this;
    }

    TProcess *fPullFromStore()
    {
        cout << "fPullFromStore \r\n";
        return this;
    }

    TProcess *fPushToMarketPlace()
    {
        cout << "fPushToMarketPlace \r\n";
        return this;
    }

    TProcess *fSale()
    {
        this->fPullFromStore();
        this->fPushToMarketPlace();
        cout << "fSale \r\n";
        return this;
    }
};

void TestCore()
{

    Core *core = new Core();

    BaseFabric *fabric = new BaseFabric(0, core);
    core->fAdd(fabric);

    BaseObject *obj1 = new BaseObject(1);
    BaseObject *obj2 = new BaseObject(1);

    // core->fAdd(obj1);
    // core->fAdd(obj2);

    core->fTick();
    core->fTick();
    core->fTick();
    core->fTick();

    delete core;

}


void TestTProcess()
{
    TProcess *p = new TProcess();
    p->fStart()->
    fMakeChoco()->
    fSale()->
    fFinish();
}

BaseObject *testB(BaseObject *obj)
{
    return obj->fClone();
}

void testCloneObj()
{
    BaseStore *o1 = new BaseStore(1);
    BaseStore *o2 = dynamic_cast<BaseStore *>(testB(o1));

    o2->sCaption = "o2";
    o1->fPrint();
    o2->fPrint();
    cout << o2->iCapacity << "\r\n";
}

int main()
{
    TestTProcess();
    return 0;
}
