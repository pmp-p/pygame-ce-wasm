from typing import (
    Any,
    Dict,
    List,
    Optional,
    Union,
    final,
)

from ._common import Sequence

@final
class Event:
    type: int
    dict: Dict[str, Any]
    __dict__: Dict[str, Any]
    __hash__: None  # type: ignore
    def __init__(
        self, type: int, dict: Dict[str, Any] = ..., **kwargs: Any
    ) -> None: ...
    def __getattribute__(self, name: str) -> Any: ...
    def __setattr__(self, name: str, value: Any) -> None: ...
    def __delattr__(self, name: str) -> None: ...
    def __bool__(self) -> bool: ...

_EventTypes = Union[int, Sequence[int]]

def pump() -> None: ...
def get(
    eventtype: Optional[_EventTypes] = None,
    pump: Any = True,
    exclude: Optional[_EventTypes] = None,
) -> List[Event]: ...
def poll() -> Event: ...
def wait(timeout: int = 0) -> Event: ...
def peek(eventtype: Optional[_EventTypes] = None, pump: Any = True) -> bool: ...
def clear(eventtype: Optional[_EventTypes] = None, pump: Any = True) -> None: ...
def event_name(type: int, /) -> str: ...
def set_blocked(type: Optional[_EventTypes], /) -> None: ...
def set_allowed(type: Optional[_EventTypes], /) -> None: ...
def get_blocked(type: _EventTypes, /) -> bool: ...
def set_grab(grab: bool, /) -> None: ...
def get_grab() -> bool: ...
def post(event: Event, /) -> bool: ...
def custom_type() -> int: ...

EventType = Event
