//
// Created by brout_m on 04/04/17.
//

#include <algorithm>
#include <iostream>
#include "Centipede.hpp"
#include "CentipedeKiller.hpp"

arcade::CentipedePart::CentipedePart(const arcade::Vector2s &pos) :
        ALivingEntity(pos,
                      TileType::EVIL_DUDE,
                      TileTypeEvolution::ENEMY,
                      Color::White,
                      1,
                      false)
{
}

void arcade::CentipedePart::setNb(size_t nb)
{
    _nb = nb;
}

void arcade::CentipedePart::move()
{
}

void arcade::CentipedePart::action()
{
}

void arcade::CentipedePart::updatePlayerInput(std::vector<arcade::Event> &events)
{
    (void)events;
}

size_t arcade::CentipedePart::getNb() const
{
    return (_nb);
}

arcade::CentipedePart &arcade::CentipedePart::operator=(const arcade::CentipedePart &centipedePart)
{
    _nb = centipedePart._nb;
    abs = centipedePart.abs;
    prev = centipedePart.prev;
    hp = centipedePart.hp;
    collidable = centipedePart.collidable;
    type = centipedePart.type;
    typeEvolution = centipedePart.typeEvolution;
    shift = centipedePart.shift;
    color = centipedePart.color;
    spriteSet = centipedePart.spriteSet;
    sprite = centipedePart.sprite;
    return (*this);
}

arcade::Centipede::Centipede(Vector2s const& pos,
                             size_t length,
                             CentipedeDirection dirH,
                             CentipedeDirection dirV) :
        _poped(length),
        _start(pos),
        _directionH(dirH),
        _directionV(dirV)
{
    if (length == DEFAULT_SIZE)
    {
        _body.push_back(new CentipedePart(pos));
        _body.back()->setColor(Color::White);
        if (_poped)
            --_poped;
    }
}

arcade::Centipede::Centipede(const arcade::Centipede &centipede) :
        _poped(centipede._poped),
        _start(centipede._start),
        _directionH(centipede._directionH),
        _directionV(centipede._directionV)
{
    _body = centipede._body;
}

std::deque<arcade::CentipedePart *> &arcade::Centipede::getBody()
{
    return _body;
}

bool arcade::Centipede::hitByBullet(arcade::Bullet &bullet,
                                    std::list<Centipede*> &centipedes,
                                    std::list<Mushroom*> &mushrooms)
{
    std::deque<arcade::CentipedePart*>::iterator it;
    size_t pos;

    it = std::find_if(_body.begin(), _body.end(),
                      [&bullet](CentipedePart *part)
                      {
                          return (part->getAbs() == bullet.getAbs());
                      });

    if (it != _body.end())
    {
        pos = (*it)->getNb();

        if (pos == 1) {
            mushrooms.push_back(new Mushroom((*it)->getAbs()));
            _body.pop_front();
            if (_body.size())
                setBody();
        } else if (pos == _body.size()) {
            mushrooms.push_back(new Mushroom((*it)->getAbs()));
            _body.pop_back();
        } else {
            split(pos, mushrooms, centipedes);
            _poped = 0;
        }
        return (true);
    }
    return (false);
}

void arcade::Centipede::split(size_t pos, std::list<Mushroom*> &mushrooms,
                              std::list<Centipede*> &centipedes)
{
    size_t i;
    std::deque<arcade::CentipedePart*> newCentipede;

    i = _body.size();
    while (i >= pos)
    {
        newCentipede.push_front(std::move(_body.back()));
        _body.pop_back();
        --i;
    }

    mushrooms.push_back(new Mushroom(newCentipede.front()->getAbs()));
    newCentipede.pop_front();
    centipedes.push_back(new Centipede(newCentipede.front()->getAbs(), _poped));
    centipedes.back()->setBody(newCentipede);
    centipedes.back()->setBody();
    centipedes.front()->getBody().front()->setColor(Color::White);
}

arcade::Centipede &arcade::Centipede::operator=(const arcade::Centipede &centipede) {
    _body = centipede._body;
    _poped = centipede._poped;
    _start = centipede._start;
    _directionH = centipede._directionH;
    _directionV = centipede._directionV;
    return *this;
}


void arcade::Centipede::setBody(std::deque<CentipedePart*> &newBody)
{
    _body = newBody;
}

void arcade::Centipede::setBody()
{
    std::deque<arcade::CentipedePart*>::iterator it;

    it = _body.begin();
    for (size_t i = 1; i <= _body.size(); ++i) {
        (*it)->setNb(i);
        ++it;
    }
}

void arcade::Centipede::oneTurn(std::list<Centipede*> &centipedes,
                                std::list<Mushroom*> &mushrooms,
                                Map const& map)
{
    moveBody();
    moveHead(centipedes, mushrooms, map);
    if (_poped) {
        _body.push_back(new CentipedePart(_start));
        _body.back()->setColor(Color::Green);
        setBody();
        --_poped;
    }
}

bool arcade::Centipede::checkCentipedeCollision(std::list<arcade::Centipede*> &centipedes,
                                                Vector2s const& pos)
{
    for (Centipede *centipede : centipedes)
    {
        if (centipede->_body.front()->getAbs() != _body.front()->getAbs() &&
            std::find_if(centipede->_body.cbegin(), centipede->_body.cend(),
                         [&pos](const CentipedePart *part) {
                             return (pos == part->getAbs());
                         }) != centipede->_body.cend())
            return true;
    }
    return false;
}

void arcade::Centipede::moveHead(std::list<arcade::Centipede*> &centipedes,
                                 std::list<arcade::Mushroom*> &mushrooms,
                                 const arcade::Map &map)
{
    const Vector2s &_abs = _body.front()->getAbs();
    Vector2s east(_abs.x + 1, _abs.y);
    Vector2s west(_abs.x - 1, _abs.y);

    if (_directionH == WEST)
    {
        if (_abs.x == 0 ||
            std::find_if(mushrooms.cbegin(), mushrooms.cend(), [&west](const Mushroom *mush) {
                return (mush->getAbs() == west);
            }) != mushrooms.cend() || checkCentipedeCollision(centipedes, west))
        {
            testMove(map, _abs);
            _directionH = EAST;
        }
        else
            _body.front()->setAbs(west);
    }
    else
    {
        if (_abs.x == map.getWidth() - 1 ||
            std::find_if(mushrooms.cbegin(), mushrooms.cend(), [&east](const Mushroom *mush) {
                return (mush->getAbs() == east);
            }) != mushrooms.cend() || checkCentipedeCollision(centipedes, east))
        {
            testMove(map, _abs);
            _directionH = WEST;
        }
        else
            _body.front()->setAbs(east);
    }
}

void arcade::Centipede::testMove(const arcade::Map &map, const arcade::Vector2s &_abs)
{
    Vector2s north(_abs.x, _abs.y - 1);
    Vector2s south(_abs.x, _abs.y + 1);

    if (_directionV == SOUTH)
    {
        if (_abs.y == map.getHeight() - 1)
        {
            _directionV = NORTH;
            _body.front()->setAbs(north);
        }
        else
        {
            _body.front()->setAbs(south);
        }
    }
    else
    {
        if (_abs.y == 0)
        {
            _directionV = SOUTH;
            _body.front()->setAbs(south);
        }
        else
        {
            _body.front()->setAbs(north);
        }
    }
}

void arcade::Centipede::moveBody()
{
    std::deque<arcade::CentipedePart*>::reverse_iterator second;
    std::deque<arcade::CentipedePart*>::const_reverse_iterator first;

    if (_body.size() > 1)
    {
        first = _body.crbegin();
        second = _body.rbegin();
        ++first;
        while (first != _body.crend())
        {
            (*second)->setAbs((*first)->getAbs());
            ++second;
            ++first;
        }
    }
}

arcade::Centipede::~Centipede() {
    if (_body.size())
    {
        for (CentipedePart *part : _body)
        {
            if (part)
                delete part;
        }
    }
}

