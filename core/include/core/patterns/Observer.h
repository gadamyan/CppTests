//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>
#include <vector>
#include <string>

namespace cpptests::core::patterns {

class IObserver {
public:
    virtual void setMessage(const std::string& message) = 0;
    virtual ~IObserver() = default;
};

class Subject {
public:
    void notifyObservers(const std::string& message);
    void registerObserver(std::shared_ptr<IObserver> observer);
    void removeObserver(std::shared_ptr<IObserver> observer);

private:
    std::vector<std::shared_ptr<IObserver>> mObservers;
};

class User : public IObserver {
public:
    void setMessage(const std::string& message) override;
    std::string getMessage() const;

private:
    std::string mMessage;
};

}
