//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Observer.h"

using namespace cpptests::core::patterns;

void Subject::notifyObservers(const std::string& message) {
    for (const auto& observer : mObservers) {
        observer->setMessage(message);
    }
}

void Subject::registerObserver(std::shared_ptr<IObserver> observer) {
    mObservers.push_back(std::move(observer));
}

void Subject::removeObserver(std::shared_ptr<IObserver> observer) {
    mObservers.erase(std::remove(mObservers.begin(), mObservers.end(), observer), mObservers.end());
}

void User::setMessage(const std::string& message) {
    mMessage = message;
}

std::string User::getMessage() const {
    return mMessage;
}